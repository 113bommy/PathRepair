#include <bits/stdc++.h>
using namespace std;
int s, l;
int lo[100001];
int low(int v) {
  int e = 0;
  while (!(v & 1)) {
    v >>= 1;
    e++;
  }
  return e;
}
int f(int a, int b, vector<int>& s) {
  if (!a) {
    return 1;
  }
  for (int i = b; i >= 1; i--) {
    s.push_back(i);
    if (a >= lo[i] && f(a - lo[i], i - 1, s)) {
      return 1;
    }
    s.pop_back();
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> l;
  int tt = 0;
  for (int i = 1; i <= l; i++) {
    lo[i] = 1 << low(i);
    tt += lo[i];
  }
  vector<int> v;
  if (tt > s && f(s, l, v)) {
    cout << v.size() << "\n";
    cout << v[0];
    for (int i = 1; i < v.size(); i++) {
      cout << " " << v[i];
    }
    return 0;
  }
  cout << -1 << "\n";
  return 0;
}
