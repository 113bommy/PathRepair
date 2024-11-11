#include <bits/stdc++.h>
using namespace std;
int inp[200000];
int main() {
  int n;
  cin >> n;
  long long mid = 0;
  for (int i = 0; i < n; i++) cin >> inp[i], mid += inp[i];
  long long ans = 0, ans1 = 0;
  int midd = mid / n;
  for (int i = 0; i < n; i++)
    if (inp[i] <= midd) ans += (midd - inp[i]);
  if (mid % n != 0) midd++;
  for (int i = 0; i < n; i++)
    if (inp[i] > midd) ans1 += (inp[i] - midd);
  cout << max(ans1, ans) << endl;
}
