#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:264777216")
long long getPhi(int a) {
  char s[30];
  sprintf(s, "%d", a);
  int res = 0;
  for (int i = 0; s[i]; ++i) {
    res = res * 10 + 9 - (s[i] - '0');
  }
  return res;
}
long long che(int L, int R) {
  long long r = 0;
  for (int i = L; i <= R; ++i) {
    long long f = i * getPhi(i);
    if (r < f) {
      r = f;
    }
  }
  return r;
}
void Solve() {
  int L, R;
  cin >> L >> R;
  {
    char _sL[30];
    char _sR[30];
    sprintf(_sL, "%d", L);
    sprintf(_sR, "%d", R);
    string sL = _sL;
    string sR = _sR;
    while (sL.size() < sR.size()) sL = "0" + sL;
    long long res = 0;
    int pref = 0;
    for (int i = 0; i < sL.size(); ++i) {
      for (int j = sL[i] - '0'; j < sR[i] - '0'; ++j) {
        int val = pref * 10 + j;
        for (int k = i + 1; k < sL.size(); ++k) val = val * 10 + 9;
        res = max(res, val * getPhi(val));
      }
      pref = pref * 10 + sR[i] - '0';
    }
    res = max(res, L * getPhi(L));
    res = max(res, R * getPhi(R));
    cout << res << endl;
  }
}
int main() {
  Solve();
  return 0;
}
