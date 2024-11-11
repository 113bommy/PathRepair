#include <bits/stdc++.h>
using namespace std;
const long long LIMIT = 10000000;
long long n, k;
int signum(long long x) {
  if (x < 0) {
    return -1;
  }
  return x > 0;
}
bool wavy(long long x) {
  if (x < 10) {
    return true;
  }
  int dist1 = signum(x / 10 % 10 - x % 10), dist2 = 0;
  if (dist1 == 0) {
    return false;
  }
  x /= 10;
  while (x > 10) {
    dist2 = signum(x / 10 % 10 - x % 10);
    if (dist1 * dist2 != -1) {
      return false;
    }
    dist1 = dist2;
    x /= 10;
  }
  return true;
}
void gen_wavy_range(long long ini, long long end, vector<long long>& range) {
  for (long long i = ini; i < end; i++) {
    if (wavy(i)) {
      range.push_back(i);
    }
  }
}
int cont[807510][10][2];
int mapping[LIMIT];
void solve() {
  if (n > LIMIT) {
    int cont = 0;
    for (long long i = n * k; i < LIMIT * LIMIT; i += n) {
      if (wavy(i)) {
        cont++;
        if (cont == k) {
          cout << i;
          return;
        }
      }
    }
  } else {
    vector<long long> lower;
    gen_wavy_range(LIMIT / 100, LIMIT, lower);
    vector<long long> higher;
    gen_wavy_range(1, LIMIT / 100, higher);
    higher.insert(higher.end(), lower.begin(), lower.end());
    for (long long h : higher) {
      if (h % n == 0) {
        if (--k == 0) {
          cout << h;
          return;
        }
      }
    }
    memset(mapping, -1, sizeof(mapping));
    for (long long l : lower) {
      mapping[l % n] = 1;
    }
    int inc = 0;
    for (int i = 0; i < LIMIT; ++i) {
      if (mapping[i] == 1) {
        mapping[i] = inc++;
      }
    }
    memset(cont, 0, sizeof(cont));
    for (long long l : lower) {
      cont[mapping[l % n]][l / (LIMIT / 10)]
          [max(0, signum(l / 10 % 10 - l % 10))]++;
    }
    for (long long h : higher) {
      int r = (n - LIMIT * h % n) % n, ini = 0, end = 10;
      if (mapping[r] != -1) {
        if (h >= 10) {
          int dir = signum(h / 10 % 10 - h % 10);
          if (dir > 0) {
            ini = h % 10 + 1;
          } else {
            end = h % 10;
          }
        }
        for (int d = ini; d < end; d++)
          if (d != h % 10) {
            int cur = cont[mapping[r]][d][max(0, signum(h % 10 - d))];
            if (k > cur) {
              k -= cur;
            } else {
              for (long long l : lower)
                if (l / (LIMIT / 10) == d) {
                  long long x = h * LIMIT + l;
                  if (wavy(x) && x % n == 0 && --k == 0) {
                    cout << x;
                    return;
                  }
                }
            }
          }
      }
    }
  }
  cout << -1;
}
int main() {
  while (cin >> n >> k) {
    solve();
  }
  return 0;
}
