#include <bits/stdc++.h>
using namespace std;
struct cientificos {
  int ki, ai, xi, yi, mi;
  queue<int> problems;
  cientificos() {
    this->ki = 0;
    this->ai = 0;
    this->xi = 0;
    this->yi = 0;
    this->mi = 0;
  }

 public:
  void valorProblems() {
    problems.push(ai);
    long long last = ai;
    for (int i = (1), _i = (ki); i < _i; i++) {
      long long aux = ((last * xi + yi) % mi);
      last = aux;
      problems.push((int)aux);
    }
  }
  void poper() { problems.pop(); }
};
int main() {
  int ct;
  scanf("%d", &ct);
  vector<cientificos> lista;
  for (int i = (0), _i = (ct); i < _i; i++) {
    cientificos now;
    scanf("%d %d %d %d %d", &now.ki, &now.ai, &now.xi, &now.yi, &now.mi);
    now.valorProblems();
    lista.push_back(now);
  }
  vector<pair<int, int> > out;
  int lsize = lista.size();
  int badpairs = 0;
  while (true) {
    vector<pair<int, int> > casians;
    for (int i = (0), _i = (lsize); i < _i; i++) {
      if (!lista[i].problems.empty()) {
        casians.push_back(pair<int, int>(lista[i].problems.front(), i));
      }
    }
    if (casians.empty()) break;
    sort(casians.begin(), casians.end());
    pair<int, int> mini = pair<int, int>((int)1e9 + 1, -1);
    if (out.size() != 0) {
      for (int i = (0), _i = (casians.size()); i < _i; i++) {
        if (casians[i].first >= out.back().first) {
          mini = casians[i];
          break;
        }
      }
      if (mini.second == -1) {
        mini = casians[0];
      }
      if (out.back().first > mini.first) {
        badpairs++;
      }
    } else {
      mini = casians[0];
    }
    out.push_back(pair<int, int>(mini.first, mini.second + 1));
    lista[mini.second].poper();
  }
  printf("%d\n", badpairs);
  for (int i = (0), _i = (out.size()); i < _i; i++) {
    printf("%d %d\n", out[i].first, out[i].second);
  }
  return 0;
}
