#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int M = 2e6 + 9;
const int INF = 1e9 + 7;
int main() {
  int n;
  int a[22222];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m;
  m = 3;
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == m) {
      flag = 1;
      break;
    } else {
      for (int j = 1; j <= 3; ++j) {
        if (a[i] != j && m != j) {
          m = j;
          break;
        }
      }
    }
  }
  if (!flag)
    printf("YES\n");
  else
    printf("NO\n");
}
