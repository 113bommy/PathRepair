#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  int target;
  int price;
  int redenB;
  node* next;
};
class graf {
 public:
  node** lista;
  int n;
  vector<long long> taken;
  priority_queue<pair<long long, int> > pqPrim;
  graf(int n) {
    n++;
    this->n = n;
    lista = new node*[n];
    for (int ctr1 = 0; ctr1 < n; ctr1++) {
      lista[ctr1] = NULL;
    }
  }
  void add(int x, int y, int price, int rb) {
    node* cur = new node;
    cur->target = y;
    cur->price = price;
    cur->next = NULL;
    cur->redenB = rb;
    if (lista[x] == NULL) {
      lista[x] = cur;
    } else {
      cur->next = lista[x];
      lista[x] = cur;
    }
  }
  void print() {
    for (int ctr1 = 0; ctr1 < n; ctr1++) {
      cout << ctr1 << ": ";
      node* temp = lista[ctr1];
      while (temp != NULL) {
        cout << temp->target << " ";
        temp = temp->next;
      }
      cout << endl;
    }
  }
  vector<long long> Djikstra(int s) {
    vector<long long> dist(n, 1000000000000000000);
    vector<long long> lastdist(n, -1);
    vector<long long> from(n, -1);
    dist[s] = 0;
    lastdist[s] = 0;
    from[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        pq;
    pq.push(pair<long long, int>(0, s));
    while (!pq.empty()) {
      pair<long long, int> front = pq.top();
      pq.pop();
      int d = front.first, u = front.second;
      if (d > dist[u]) continue;
      for (node* ctr = lista[u]; ctr != NULL; ctr = ctr->next) {
        pair<long long, int> v(ctr->target, ctr->price);
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;
          lastdist[v.first] = v.second;
          from[v.first] = ctr->redenB;
          pq.push(pair<long long, int>(dist[v.first], v.first));
        }
        if (dist[u] + v.second == dist[v.first]) {
          if (lastdist[v.first] > v.second) {
            lastdist[v.first] = v.second;
            from[v.first] = from[v.first] = ctr->redenB;
            ;
          }
        }
      }
    }
    int rez = 0;
    for (int ctr1 = 1; ctr1 < from.size(); ctr1++) {
      if (ctr1 != s) rez += lastdist[ctr1];
    }
    cout << rez << endl;
    for (int ctr1 = 1; ctr1 < from.size(); ctr1++) {
      if (ctr1 != s) cout << from[ctr1] << " ";
    }
    vector<long long> a;
    return a;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  graf g(n);
  int u, v, w;
  for (int ctr1 = 1; ctr1 <= m; ctr1++) {
    cin >> u >> v >> w;
    g.add(u, v, w, ctr1);
    g.add(v, u, w, ctr1);
  }
  int source;
  cin >> source;
  g.Djikstra(source);
  return 0;
}
