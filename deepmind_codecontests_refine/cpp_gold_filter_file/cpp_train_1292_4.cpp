#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int sv[maxn + 1] = {1, 1, 0};
vector<int> pm;
void sieve() {
  pm.push_back(2);
  for (int i = 4; i <= maxn; i += 2) sv[i] = 2;
  for (int i = 3; i <= maxn; i += 2)
    if (!sv[i]) {
      pm.push_back(i);
      for (int j = i + i; j <= maxn; j += i) sv[j] = i;
    }
}
bool verify(vector<int>& a, int kh, int k) {
  if (((int)(a).size()) <= k) return false;
  for (int i = (0); i <= ((6) - 1); ++i) {
    int cnt = 0;
    for (int j = (0); j <= ((((int)(a).size())) - 1); ++j)
      if (a[j] % pm[i] == 0) ++cnt;
    if (cnt and cnt < kh) {
      cerr << pm[i] << "+" << '\n';
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  sieve();
  int k;
  while (cin >> k) {
    int alim = 2 * k * k;
    int kp = (k + 1) / 2;
    vector<int> a;
    int pw = 1;
    while (((int)(a).size()) <= k) {
      int tpw = pw;
      for (int i = (0); i <= ((kp)-1); ++i) {
        int tpwj = tpw;
        for (int j = (0); j <= ((kp)-1); ++j) {
          int tpwu = tpwj;
          for (int u = (0); u <= ((kp)-1); ++u) {
            int tpwv = tpwu;
            for (int v = (0); v <= ((kp)-1); ++v) {
              int tpww = tpwv;
              for (int w = (0); w <= ((kp)-1); ++w) {
                a.push_back(tpww);
                if (k <= 5000) break;
                tpww *= 13;
                if (((int)(a).size()) == k + 1 or tpww > alim) break;
              }
              if (k < 1334) break;
              tpwv *= 11;
              if (((int)(a).size()) == k + 1 or tpwv > alim) break;
            }
            if (k < 404) break;
            tpwu *= 7;
            if (((int)(a).size()) == k + 1 or tpwu > alim) break;
          }
          if (k < 65) break;
          tpwj *= 5;
          if (((int)(a).size()) == k + 1 or tpwj > alim) break;
        }
        if (k < 7) break;
        tpw *= 3;
        if (((int)(a).size()) == k + 1 or tpw > alim) break;
      }
      pw *= 2;
      if (pw > alim) break;
    }
    sort((a).begin(), (a).end());
    for (int i = (1); i <= ((((int)(a).size()) - 1)); ++i) cout << a[i] << ' ';
    cout << '\n';
  }
  return 0;
}
