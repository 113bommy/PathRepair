#include <bits/stdc++.h>
using namespace std;
void File() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
bool check(int num);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (check(n)) {
    cout << 1 << endl;
    cout << n << endl;
    return 0;
  }
  int ans1 = n;
  while (!check(ans1)) ans1 -= 2;
  n -= ans1;
  int ans2 = n / 2, ans3 = n / 2;
  if (n == 2) {
    cout << 2 << endl;
    cout << ans1 << " " << 2 << endl;
    return 0;
  }
  while (!check(ans2) || !check(ans3)) {
    if (ans2 % 2 == 0)
      ans2--;
    else
      ans2 -= 2;
    if (ans3 % 2 == 0)
      ans3++;
    else
      ans3 += 2;
  }
  cout << 3 << endl;
  cout << ans1 << " " << ans2 << " " << ans3 << endl;
  return 0;
}
bool check(int num) {
  if (num % 2 == 0 && num != 2) return 0;
  if (num == 2) return 1;
  int sz = sqrt(num);
  for (int i = 3; i <= sz; i += 2)
    if (num % i == 0) return 0;
  return 1;
}
