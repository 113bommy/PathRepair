#include <bits/stdc++.h>
using namespace std;
const long long nInf = -1000000000;
const long long pInf = 1000000000;
const long long mod = 1000000007;
const int MAXN = 1000;
int a, b, m, r[MAXN], used[MAXN];
void getdata();
void preproc();
void solve();
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) {
    getdata();
    preproc();
    solve();
  }
  return 0;
}
void getdata() { scanf("%d %d %d %d", &a, &b, &m, &r[0]); }
void preproc() {}
void solve() {
  fill(used, used + MAXN, -1);
  for (int i = 1; i < 100000000; i++) {
    r[i] = (a * r[i - 1] + b) % m;
    if (used[r[i]] != -1) {
      printf("%d\n", i - used[r[i]]);
      return;
    }
    used[r[i]] = i;
  }
}
