#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int n, k;
int a[211111];
int nx[211111];
int b[211111];
bool used[211111];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    used[i] = false;
    b[i] = n + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    nx[i] = b[a[i]];
    b[a[i]] = i;
  }
  int t = 0;
  int money = 0;
  for (int i = 0; i < n; i++) {
    if (used[a[i]]) continue;
    if (t == k) {
      int d = 0;
      int b_nx = 0;
      for (int j = 0; j < i; j++)
        if (used[a[j]] && nx[j] > b_nx) {
          b_nx = nx[j];
          d = j;
        }
      used[a[d]] = false;
      t--;
    }
    used[a[i]] = true;
    t++;
    money++;
    if (nx[i] == n + 1) {
      used[a[i]] = false;
      t--;
    }
  }
  cout << money;
  return 0;
}
