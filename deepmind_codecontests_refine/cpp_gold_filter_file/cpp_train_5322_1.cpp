#include <bits/stdc++.h>
using namespace std;
const int MN = 1000 + 10;
int n, m, h, arr[MN];
int s1, s2;
long double ans = 1.0;
int main() {
  cin >> n >> m >> h;
  h--;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    if (i != h) s2 += arr[i];
  }
  arr[h]--;
  n--;
  s1 = arr[h];
  if (s1 + s2 < n)
    printf("%0.10lf", -ans);
  else if (s1 == 0)
    printf("%0.10lf", 0.0 * ans);
  else {
    int st1 = s2 - n + 1;
    int fin1 = s1 + s2 - n;
    int st2 = s2 + 1;
    int fin2 = s1 + s2;
    int curr1 = st1;
    int curr2 = st2;
    ans = curr1;
    curr1++;
    while (curr1 <= fin1) {
      if (ans < 1.0 || curr2 > fin2) {
        ans *= curr1;
        curr1++;
      } else if (curr2 <= fin2) {
        ans /= curr2;
        curr2++;
      }
    }
    while (curr2 <= fin2) {
      ans /= curr2;
      curr2++;
    }
    ans = min(ans, (long double)1.0);
    ans = 1.0 - ans;
    printf("%0.10lf", ans);
  }
  return 0;
}
