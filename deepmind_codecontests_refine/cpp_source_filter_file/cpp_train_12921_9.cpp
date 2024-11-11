#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int a[maxn], b[maxn], ve[maxn], ans[maxn];
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (ve[b[i]]) continue;
    while (1) {
      ans[i]++;
      ve[a[j]]++;
      j++;
      if (ve[b[i]]) break;
    }
  }
  for (int i = 0; i < n; i++) cout << ve[i] << " ";
}
