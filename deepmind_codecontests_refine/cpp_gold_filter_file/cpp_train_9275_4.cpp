#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn], pos[maxn];
char ret[maxn];
bool win[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  ret[1] = 'A';
  ret[n] = 'B';
  for (int i = 1; i <= n; i++) win[i] = false;
  win[1] = true;
  int winpos = pos[n];
  for (int i = n - 1; i > 1; i--) {
    int idx = pos[i];
    if (abs(winpos - idx) % i == 0) {
      ret[i] = 'A';
      win[i] = true;
      continue;
    }
    ret[i] = 'B';
    for (int j = idx + i; j <= n; j += i) {
      if (a[j] > i) {
        if (!win[a[j]]) {
          ret[i] = 'A';
          win[i] = true;
          break;
        }
      }
    }
    for (int j = idx - i; j >= 1; j -= i) {
      if (a[j] > i) {
        if (!win[a[j]]) {
          ret[i] = 'A';
          win[i] = true;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << ret[a[i]];
  cout << "\n";
  return 0;
}
