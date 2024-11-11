#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  int l = v.size();
  for (int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, L;
  cin >> n >> L;
  vector<long long int> b, g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  for (int i = 0, k; i < n; ++i) {
    cin >> k;
    b.push_back(k);
    b.push_back(k + L);
    b.push_back(k - L);
  }
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  auto check = [&](int c) {
    long long int ll = 0, rr = 3 * n - 1;
    for (int i = 0; i < n; ++i) {
      while (g[i] - b[ll] > c) ll++;
      while (b[rr] - g[i] > c) rr--;
      ll++;
      rr++;
    }
    return ll <= rr;
  };
  long long int rt = L / 2, lt = 0, md;
  while (lt != rt) {
    md = (rt + lt) / 2;
    if (check(md)) {
      rt = md;
    } else {
      lt = md + 1;
    }
  }
  cout << lt << endl;
  return 0;
}
