#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
const int inf = 2e9 + 5;
int n;
int a[N];
int first[N];
bool tmp = false;
void xuli() {
  int s = 0;
  for (int i = 1; i <= n; i++) {
    if (first[i] == 1)
      s += a[i];
    else
      s -= a[i];
  }
  if (s % 360 == 0) tmp = true;
}
void thu(int k) {
  if (k > n) {
    xuli();
    return;
  }
  for (int i = 1; i <= 2; i++) {
    first[k] = i;
    thu(k + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  thu(1);
  if (tmp)
    cout << "YES";
  else
    cout << "NO";
}
