#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
double Cp = 1.2;
class State {
 public:
  vector<int> commonNeigh, click;
  vector<State*> son;
  int reward, nvisited;
  State() {
    commonNeigh.clear();
    click.clear();
    reward = nvisited = 0;
    son.clear();
  }
  double GetUct(State* u, int nvis) {
    if (u->nvisited == 0) return INF;
    return u->reward / (double)u->nvisited +
           (Cp)*sqrt((2 * log(nvis)) / (double)u->nvisited);
  }
};
class MCTS {
 private:
  State* root;
  vector<vector<int> > graph;

 public:
  static double Cp;
  void AddEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  State* BestChild(State*& u) {
    int nvisited = u->nvisited;
    double maxi = -INF;
    State* best = nullptr;
    if (u->son.size() == 0) {
      return best;
    }
    for (auto son_u : u->son) {
      double uct = son_u->GetUct(son_u, nvisited);
      if (uct > maxi) maxi = uct, best = son_u;
    }
    return best;
  }
  bool isTerminal(State*& u) { return (u->commonNeigh.size() > 0); }
  State* Expand(State*& u) {
    int cur_vertex = u->commonNeigh.back();
    u->commonNeigh.pop_back();
    set<int> common;
    for (int x : u->commonNeigh) common.insert(x);
    State* next = new State();
    next->click = u->click;
    next->click.push_back(cur_vertex);
    next->nvisited = 1;
    for (int v : graph[cur_vertex])
      if (common.count(v)) next->commonNeigh.push_back(v);
    return next;
  }
  MCTS(int n) {
    graph.clear();
    graph.resize(n);
    root = new State();
    for (int i = 0; i < n; i++) root->commonNeigh.push_back(i);
  }
  int Build(State*& u) {
    u->nvisited++;
    if (isTerminal(u)) {
      State* Next = Expand(u);
      int benefit = Simulation(Next);
      Next->reward = benefit;
      u->reward = max(u->reward, benefit);
      u->son.push_back(Next);
      return benefit;
    }
    State* Next = BestChild(u);
    if (Next == nullptr) return -1;
    int benefit = Build(Next);
    u->reward = max(u->reward, benefit);
    return benefit;
  }
  int Process() {
    int ok = 1;
    while (ok > 0) {
      ok = Build(root);
    }
    return root->reward;
  }
  int Simulation(State*& u) {
    set<int> neig;
    for (int x : u->commonNeigh) neig.insert(x);
    int click = u->click.size();
    while (neig.size() > 0) {
      int next = -1;
      int maxi = 0;
      for (int x : neig) {
        int n = 0;
        for (int y : graph[x])
          if (neig.count(y)) n++;
        if (n >= maxi) maxi = n, next = x;
      }
      set<int> prox;
      for (int x : graph[next])
        if (neig.count(x)) prox.insert(x);
      neig = prox;
      click++;
    }
    return click;
  }
  void clear(State* u) {
    for (auto son_u : u->son) clear(son_u);
    u->son.clear();
    delete u;
  }
  void delete_all() { clear(root); }
};
int main() {
  int n, k;
  cin >> n >> k;
  MCTS test(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (i > j and x) {
        test.AddEdge(i, j);
      }
    }
  }
  int m = 0;
  for (int i = 0; i < 100; i++) {
    m = test.Process();
  }
  test.delete_all();
  cout << fixed << setprecision(15);
  cout << (k * k * (m - 1)) / (2.0 * m) << endl;
  return 0;
}
