#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n;
  long long a[n];
  long long in = 0;
  long long s1 = 0, s2 = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    s1 += a[i];
  }
  cin >> m;
  long long b[m];
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    s2 += b[i];
  }
  vector<pair<long long, long long> > c, d;
  c.resize((n * (n - 1)) / 2);
  d.resize((m * (m - 1)) / 2);
  long long v = LONG_MAX, x1 = -1, x2 = -1, y1 = -1, y2 = -1;
  v = abs(s1 - s2);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      c[in] = {2 * a[i] + 2 * a[j], in};
      in++;
    }
  }
  in = 0;
  for (long long i = 0; i < m; i++) {
    for (long long j = i + 1; j < m; j++) {
      d[in] = {2 * b[i] + 2 * b[j], in};
      in++;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (abs(s1 - s2 + 2 * (b[j] - a[i])) <= v) {
        v = abs(s1 - s2 + 2 * (b[j] - a[i]));
        x1 = i;
        y1 = j;
      }
    }
  }
  vector<pair<long long, long long> >::iterator it;
  sort(d.begin(), d.end());
  for (long long i = 0; i < (n * (n - 1)) / 2; i++) {
    it = lower_bound(d.begin(), d.end(),
                     make_pair(s2 - s1 + c[i].first, (long long)-1));
    if (it == d.end()) {
      in = (m * (m - 1)) / 2 - 1;
    } else {
      in = it - d.begin();
    }
    if (in >= 0 && d.size() > 0 &&
        abs(s2 - s1 + c[i].first - d[in].first) < v) {
      v = abs(s2 - s1 + c[i].first - d[in].first);
      x2 = c[i].second;
      y2 = d[in].second;
    }
    if (in - 1 >= 0 && d.size() > 0 &&
        abs(s2 - s1 + c[i].first - d[in - 1].first) < v) {
      v = abs(s2 - s1 + c[i].first - d[in - 1].first);
      x2 = c[i].second;
      y2 = d[in - 1].second;
    }
  }
  cout << v << "\n";
  if (y1 == -1) {
    cout << 0 << "\n";
    return 0;
  }
  if (y2 == -1) {
    cout << 1 << "\n";
    cout << x1 + 1 << " " << y1 + 1 << "\n";
    return 0;
  }
  in = 0;
  bool v1 = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (in == x2) {
        x1 = i;
        x2 = j;
        v1 = 1;
        break;
      }
      in++;
    }
    if (v1) break;
  }
  in = 0;
  v1 = 0;
  for (long long i = 0; i < m; i++) {
    for (long long j = i + 1; j < m; j++) {
      if (in == y2) {
        y1 = i;
        y2 = j;
        v1 = 1;
        break;
      }
      in++;
    }
    if (v1) break;
  }
  cout << 2 << "\n";
  cout << x1 + 1 << " " << y1 + 1 << "\n";
  cout << x2 + 1 << " " << y2 + 1 << "\n";
  return 0;
}
