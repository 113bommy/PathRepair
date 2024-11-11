#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long double PI = 3.1415926535897932384626433832795028841;
map<string, int> ssol;
void checkAdd(string vs) {
  if (ssol.find(vs) != ssol.end()) {
    return;
  }
  ssol[vs] = 1;
}
bool TST = 0;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
void Show(int *QQ, int N) {
  if (not TST) {
    return;
  }
  for (int x = 0; x < N; x++) {
    cout << QQ[x];
    if (x != N - 1) {
      cout << ',';
    }
  }
  cout << '\n';
}
void ShowLL(long long *QQ, int N) {
  if (not TST) {
    return;
  }
  for (int x = 0; x < N; x++) {
    cout << QQ[x];
    if (x != N - 1) {
      cout << ',';
    }
  }
  cout << '\n';
}
int a1[4];
int b1[4];
int gd(int num, int d) {
  while (d--) num /= 10;
  return num % 10;
}
set<int> pos;
bool dif(int n) {
  if (gd(n, 0) == gd(n, 1)) return 0;
  if (gd(n, 0) == gd(n, 2)) return 0;
  if (gd(n, 0) == gd(n, 3)) return 0;
  if (gd(n, 1) == gd(n, 2)) return 0;
  if (gd(n, 1) == gd(n, 3)) return 0;
  if (gd(n, 2) == gd(n, 3)) return 0;
  return 1;
}
bool valid(int original, int target, int b, int c) {
  int cnt = 0;
  while (cnt < 4) {
    a1[cnt++] = original % 10;
    original /= 10;
  }
  cnt = 0;
  while (cnt < 4) {
    b1[cnt++] = target % 10;
    target /= 10;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a1[i] == b1[j]) {
        if (i == j) b--;
        if (i != j) c--;
      }
    }
  }
  return (b == 0) and (c == 0);
}
int main() {
  for (int i = 0; i < 10000; i++) {
    if (dif(i)) pos.insert(i);
  }
  int last_c = 0;
  int last_b = 0;
  int st = 1;
  while (pos.size() > 1) {
    vector<int> vls;
    for (set<int>::iterator it = pos.begin(); it != pos.end(); it++)
      vls.push_back(*it);
    int ans;
    if (st == 0) {
      int win = -1;
      int min_worst_case = -1;
      for (int i = 0; i < vls.size(); i++) {
        int max_sum = 0;
        for (int b = 0; b <= 4; b++) {
          for (int c = 0; c <= 4; c++) {
            if (b + c > 4) continue;
            int sum = 0;
            for (int j = 0; j < vls.size(); j++) {
              if (valid(vls[i], vls[j], b, c)) {
                sum++;
              }
            }
            max_sum = max(max_sum, sum);
          }
        }
        if (min_worst_case < max_sum) win = i;
        min_worst_case = min(min_worst_case, max_sum);
      }
      ans = vls[win];
    } else {
      ans = 1234;
      st = 0;
    }
    if (ans < 10) cout << 0;
    if (ans < 100) cout << 0;
    if (ans < 1000) cout << 0;
    cout << ans << '\n';
    fflush(stdout);
    int b, c;
    cin >> b >> c;
    if (b == 4) return 0;
    vector<int> del;
    for (int i = 0; i < vls.size(); i++) {
      if (not valid(ans, vls[i], b, c)) {
        del.push_back(vls[i]);
      }
    }
    for (int i = 0; i < del.size(); i++) {
      pos.erase(del[i]);
    }
  }
  int rta = *(pos.begin());
  if (rta < 10) cout << 0;
  if (rta < 100) cout << 0;
  if (rta < 1000) cout << 0;
  cout << rta << '\n';
  fflush(stdout);
}
