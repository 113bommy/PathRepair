#include <bits/stdc++.h>
const int MOD = 1e9;
const int N = 100005;
using namespace std;
int n;
int a[2 * N];
int temp = 0;
int inx = -1;
int main() {
  cin >> n;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > temp) {
      temp = a[i];
      inx = i;
    }
  }
  for (int i = 0; i < inx; i++)
    if (a[i] > a[i + 1]) ans = 0;
  for (int i = inx; i < n - 1; i++)
    if (a[i] < a[i + 1]) ans = 0;
  if (ans)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
