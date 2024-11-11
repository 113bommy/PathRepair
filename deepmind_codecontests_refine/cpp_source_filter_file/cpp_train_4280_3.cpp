#include <bits/stdc++.h>
using namespace std;
vector<long long> v, si;
int roo(int i) { return i == v[i] ? i : v[i] = roo(v[i]); }
void w_union(int _a, int _b) {
  int a = roo(_a);
  int b = roo(_b);
  if (a == b) return;
  if (si[a] < si[b]) {
    v[a] = v[b];
    si[b] += si[a];
  } else {
    v[b] = v[a];
    si[a] += si[b];
  }
}
int main() {
  long long n, m, a, b, k = 0;
  cin >> n >> m;
  v.resize(n + 1);
  si.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = i;
    si[i] = 1;
  }
  while (m--) {
    cin >> a >> b;
    if (roo(a) == roo(b))
      k += 1;
    else {
      w_union(a, b);
    }
  }
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(roo(v[i]));
  if (k > 0 && s.size() == 1) {
    cout << "FHTAGN!";
  } else {
    cout << "NO";
  }
  return 0;
}
