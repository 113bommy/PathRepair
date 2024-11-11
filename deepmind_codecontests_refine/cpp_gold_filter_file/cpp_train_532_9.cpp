#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  int n, k, m, ct = 0;
  cin >> n >> m >> k;
  int arr[n + 1], sch[n + 1];
  int maxx[m + 1];
  arr[0] = 0;
  memset(maxx, 0, sizeof(maxx));
  for (int i = 1; i < (int)n + 1; i++) cin >> arr[i];
  for (int i = 1; i < (int)n + 1; i++) {
    cin >> sch[i];
    if (arr[maxx[sch[i]]] < arr[i]) maxx[sch[i]] = i;
  }
  int ma[k + 1];
  for (int i = 1; i < (int)k + 1; i++) {
    cin >> ma[i];
    if (maxx[sch[ma[i]]] != ma[i]) ct++;
  }
  cout << ct;
}
