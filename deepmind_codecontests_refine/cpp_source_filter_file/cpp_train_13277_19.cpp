#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
void IO() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
const int N = (int)1e5 + 5;
int a[N];
int main() {
  IO();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  int cnt = 1;
  for (int i = 1; i <= n; i++)
    if (a[i] > cnt) cnt++;
  cout << cnt;
}
