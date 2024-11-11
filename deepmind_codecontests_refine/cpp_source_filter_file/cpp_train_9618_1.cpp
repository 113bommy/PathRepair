#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << "\n";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string second;
  cin >> second;
  long long n = second.size();
  vc<long long> grun(n + 1);
  grun[1] = 0;
  grun[2] = 0;
  for (long long i = 3; i <= n; i++) {
    set<long long> pos;
    for (long long j = 1; j < i; j++) {
      long long p = grun[j] ^ grun[i - j - 1];
      pos.insert(p);
    }
    for (long long j = 0;; j++) {
      if (pos.find(j) == pos.end()) {
        grun[i] = j;
        break;
      }
    }
  }
  long long last = 0;
  vc<pii> parts;
  for (long long i = 1; i < n; i++) {
    if (i + 1 == n || second[i - 1] != second[i + 1]) {
      parts.push_back({last, i});
      last = i;
    }
  }
  long long xo = 0;
  for (long long i = 0; i < parts.size(); i++) {
    xo ^= grun[parts[i].second - parts[i].first + 1];
  }
  cerr << "xor: " << xo << "\n";
  if (xo == 0) {
    cout << "Second\n";
  } else {
    long long found = -1;
    for (long long i = 0; i < parts.size() && found == -1; i++) {
      for (long long j = parts[i].first + 1; j < parts[i].second && found == -1;
           j++) {
        long long new_xo = xo ^ grun[j - parts[i].first] ^
                           grun[parts[i].second - j] ^
                           grun[parts[i].second - parts[i].first + 1];
        if (new_xo == 0) found = j;
      }
    }
    cout << "First\n";
    cout << found + 1 << "\n";
  }
}
