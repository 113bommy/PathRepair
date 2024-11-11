#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
using namespace std;
const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;
int A[MAX];
int main() {
  int n, s;
  cin >> n >> s;
  --s;
  int res = 0;
  for (int i = (0); i < (n); i++) {
    int x;
    scanf("%d", &x);
    if (i == s && x != 0) {
      ++res;
      x = 0;
    }
    if (i != s && x == 0) {
      x = n;
    }
    A[x]++;
  }
  int add = INF;
  if (n == 1) {
    cout << res << endl;
    return 0;
  }
  int c1 = 0;
  int c2 = 1;
  for (int h = (1); h < (n); h++) {
    c1 += (A[h] == 0);
    c2 += A[h];
    add = min(add, max(c1, n - c2));
  }
  cout << res + add << endl;
  return 0;
}
