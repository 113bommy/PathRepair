#include <bits/stdc++.h>
using namespace std;
template <class T>
T sq(T a) {
  return a * a;
}
int num[200];
int main() {
  int n;
  cin >> n;
  vector<int> v(2 * n);
  for (int i = 0; i < (n * 2); i++) {
    cin >> v[i];
    num[v[i]]++;
  }
  set<int> a, b;
  vector<int> g(2 * n);
  for (int i = 0; i < (n * 2); i++) {
    if (num[v[i]] >= 2) {
      if (a.insert(v[i]).second)
        g[i] = 1;
      else if (b.insert(v[i]).second)
        g[i] = 2;
      else
        g[i] = 3;
    }
  }
  bool nxt = 1;
  for (int i = 0; i < (n * 2); i++) {
    if (num[v[i]] == 1) {
      if (nxt)
        a.insert(v[i]), g[i] = 1;
      else
        b.insert(v[i]), g[i] = 2;
      nxt = !nxt;
    }
  }
  int cnt = a.size();
  for (int i = 0; i < (2 * n); i++) {
    if (g[i] != 3) continue;
    if (cnt < n)
      g[i] = 1;
    else
      g[i] = 2;
  }
  cout << a.size() * b.size() << endl;
  for (int i = 0; i < (2 * n); i++) {
    cout << (i ? " " : "") << g[i];
  }
  cout << endl;
  return 0;
}
