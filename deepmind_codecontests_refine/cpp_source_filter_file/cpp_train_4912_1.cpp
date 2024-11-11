#include <bits/stdc++.h>
using namespace std;
const int N = 1;
const int MOD = 1e9 + 7;
const int bm = 1;
int n, m;
int a[N];
void sinh() {
  freopen(".inp", "w", stdout);
  srand(time(0));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int dem = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      dem++;
      for (int j = i + 1; j <= n; j++)
        if (a[j] % a[i] == 0) a[j] = 0;
    }
  cout << dem;
}
