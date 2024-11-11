#include <bits/stdc++.h>
using namespace std;
int N, a, b, v[1001000];
vector<int> p;
int c[1001000];
void desc(int x) {
  int y = x;
  for (int i = 2; 1LL * i * i <= x; ++i) {
    if (y % i == 0) {
      p.push_back(i);
      while (y % i == 0) y /= i;
    }
  }
  if (y != 1) {
    p.push_back(y);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> N >> a >> b;
  for (int i = 1; i <= N; ++i) {
    cin >> v[i];
  }
  for (int j = 0; j <= 2; ++j) {
    desc(v[1] + j - 1);
    desc(v[N] + j - 1);
  }
  long long ret = 1LL * a * (N - 1);
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (auto x : p) {
    int ind1 = -1, ind2 = -1;
    for (int i = 1; i <= N; ++i) {
      if (v[i] % x == 0) {
        c[i] = a;
      } else if ((v[i] + 1) % x == 0 || (v[i] - 1) % x == 0) {
        c[i] = a - b;
      } else {
        if (ind1 == -1) ind1 = i;
        ind2 = i;
      }
    }
    if (ind1 == -1) {
      long long curr = 0;
      long long mi = 0;
      int cfs = 1, first = 1, ls = 0;
      for (int i = 1; i <= N; ++i) {
        if (curr + c[i] > 0) {
          curr = 0;
          cfs = i + 1;
        } else {
          curr += c[i];
          if (curr < mi) {
            mi = curr;
            ls = i;
            first = cfs;
          }
        }
      }
      long long sol = 1LL * a * (ls - first + 1);
      for (int i = 1; i < first; ++i) {
        if (v[i] % x) sol += b;
      }
      for (int i = ls + 1; i <= N; ++i) {
        if (v[i] % x) sol += b;
      }
      ret = min(ret, sol);
    } else {
      long long mi = 0;
      long long curr = 0;
      int first = ind1, ls = ind2;
      for (int i = ind1 - 1; i >= 1; --i) {
        curr += c[i];
        if (curr < mi) {
          mi = curr;
          first = i;
        }
      }
      curr = 0, mi = 0;
      for (int i = ind2 + 1; i <= N; ++i) {
        curr += c[i];
        if (curr < mi) {
          mi = curr;
          ls = i;
        }
      }
      long long sol = 1LL * a * (ls - first + 1);
      for (int i = 1; i < first; ++i) {
        if (v[i] % x) sol += b;
      }
      for (int i = ls + 1; i <= N; ++i) {
        if (v[i] % x) sol += b;
      }
      ret = min(ret, sol);
    }
  }
  cout << ret;
  return 0;
}
