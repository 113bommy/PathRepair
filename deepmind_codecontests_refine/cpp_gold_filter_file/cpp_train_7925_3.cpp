#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int n;
string s, t;
int a[500005], b[500005];
int MAX = 100000;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s >> t;
  vector<pair<int, int> > RR;
  int ss = 0, st = 0;
  for (int i = 0; i < (n); ++i) {
    if (i & 1) {
      ss += s[i] - '0';
      st += t[i] - '0';
    } else {
      ss -= s[i] - '0';
      st -= t[i] - '0';
    }
  }
  if (ss != st) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < (n); ++i) {
    a[i + 1] = s[i] - '0';
    b[i + 1] = t[i] - '0';
  }
  long long res = 0, cur = 0;
  for (int i = (1); i <= (n); ++i) {
    int u = a[i] - b[i];
    cur = u - cur;
    res += abs(cur);
  }
  for (int i = (1); i <= (n); ++i) {
    while (a[i] < b[i] && ((int)(RR).size()) < MAX) {
      for (int j = i + 1;; j++) {
        if ((((j - i) & 1) && a[j] != 9) || ((j - i) % 2 == 0 && a[j] != 0)) {
          for (int k = j - 1; k >= i; k--) {
            if ((k - i) & 1) {
              if (((int)(RR).size()) < MAX) {
                RR.push_back(make_pair(k, -1));
                a[k]--;
                a[k + 1]--;
              }
            } else {
              if (((int)(RR).size()) < MAX) {
                RR.push_back(make_pair(k, 1));
                a[k]++;
                a[k + 1]++;
              }
            }
          }
          break;
        }
      }
    }
    while (a[i] > b[i] && ((int)(RR).size()) < MAX) {
      for (int j = i + 1;; j++) {
        if ((((j - i) & 1) && a[j] != 0) || ((j - i) % 2 == 0 && a[j] != 9)) {
          for (int k = j - 1; k >= i; k--) {
            if ((k - i) % 2 == 0) {
              if (((int)(RR).size()) < MAX) {
                RR.push_back(make_pair(k, -1));
                a[k]--;
                a[k + 1]--;
              }
            } else {
              if (((int)(RR).size()) < MAX) {
                RR.push_back(make_pair(k, 1));
                a[k]++;
                a[k + 1]++;
              }
            }
          }
          break;
        }
      }
    }
    if (((int)(RR).size()) >= MAX) break;
  }
  cout << res << endl;
  for (int i = 0; i < (((int)(RR).size())); ++i)
    cout << RR[i].first << " " << RR[i].second << "\n";
}
int main() {
  solve();
  return 0;
}
