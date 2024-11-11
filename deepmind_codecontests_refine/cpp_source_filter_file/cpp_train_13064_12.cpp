#include <bits/stdc++.h>
using namespace std;
int n;
int arities[100001];
int legs[100001];
bool markers[100001];
list<int> graph[100001];
void parse() {
  int a, b;
  cin >> n;
  for (int it = 0; it < (100001); it++) {
    (arities)[it] = (0);
  };
  for (int it = 0; it < (100001); it++) {
    (markers)[it] = (false);
  };
  for (int it = 0; it < (100001); it++) {
    (legs)[it] = (0);
  };
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    arities[a]++;
    arities[b]++;
  }
}
void traverse(int i) {
  if (markers[i]) return;
  if (arities[i] >= 3) {
    legs[i]++;
    return;
  }
  markers[i] = true;
  for (list<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
    traverse(*it);
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    if (arities[i] == 1) traverse(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!markers[i]) {
      int r;
      for (list<int>::iterator it = graph[i].begin(); it != graph[i].end();
           ++it) {
        if (!markers[*it] && arities[*it] - min(legs[*it], 2) > 1) r++;
      }
      if (r > 2) {
        cout << "No";
        return;
      }
    }
  }
  cout << "Yes";
}
int main() {
  ios::sync_with_stdio(false);
  std::cout.precision(11);
  parse();
  solve();
  cout << endl;
  return 0;
}
