#include <bits/stdc++.h>
using namespace std;
long long int n, c, a[1003], b[1003], ans1, ans2, cnt1, cnt2;
int big(int a, int b, int e) {
  if (a - (b * e) > 0) {
    return a - b;
  } else
    return false;
}
int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    cnt1 += b[i];
    ans1 += big(a[i], cnt1, c);
  }
  for (int i = n - 1; i >= 0; i--) {
    cnt2 += b[i];
    ans2 += big(a[i], cnt2, c);
  }
  if (ans1 > ans2)
    cout << "Limak";
  else if (ans1 < ans2)
    cout << "Radewoosh";
  else
    cout << "Tie";
  return 0;
}
