#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rnd(time(nullptr));
const int N = 1e5 + 5;
set<int> ind[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    char op;
    cin >> op;
    int first;
    cin >> first;
    int val = first;
    vector<int> pr;
    for (int i = 2; i * i <= first; ++i) {
      if (first % i) continue;
      while (first % i == 0) first /= i;
      pr.push_back(i);
    }
    if (first > 1) pr.push_back(first);
    if (val == 1) {
      if (op == '+') {
        if (ind[1].count(1))
          cout << "Already on\n";
        else {
          cout << "Success\n";
          ind[1].insert(1);
        }
      } else {
        if (ind[1].count(1)) {
          cout << "Success\n";
          ind[1].erase(1);
        } else
          cout << "Already off\n";
      }
      continue;
    }
    if (op == '+') {
      bool ok = true;
      for (int p : pr) {
        if (ind[p].count(val)) {
          ok = false;
          cout << "Already on\n";
          break;
        }
        if (!ind[p].empty()) {
          ok = false;
          cout << "Conflict with " << *ind[p].begin() << "\n";
          break;
        }
      }
      if (ok) {
        cout << "Success\n";
        for (int p : pr) ind[p].insert(val);
      }
    } else {
      if (!ind[pr[0]].count(val))
        cout << "Already off\n";
      else {
        cout << "Success\n";
        for (int p : pr) ind[p].erase(val);
      }
    }
  }
}
