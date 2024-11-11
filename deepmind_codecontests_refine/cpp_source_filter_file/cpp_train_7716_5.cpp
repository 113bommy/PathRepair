#include <bits/stdc++.h>
using namespace std;
int power[31];
int n, k;
int ans[31];
bool bad = false;
void cal(int target, int num, int pow, int want) {
  if (want == 0) {
    if (num > 0) bad = true;
    return;
  }
  if (num < want) {
    bad = true;
    return;
  }
  if ((num + 1) / 2 > want) {
    if (num % 2 == 1) {
      ans[pow] += 1;
      cal(target - power[pow], num / 2, pow + 1, want - 1);
    } else
      cal(target, num / 2, pow + 1, want);
  } else {
    int change = num - want;
    ans[pow] = num - 2 * change;
    ans[pow + 1] = change;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  power[0] = 1;
  for (int i = 1; i < 31; i++) power[i] = power[i - 1] * 2;
  cin >> n >> k;
  cal(n, n, 0, k);
  int sum = 0;
  for (int i = 0; i < 31; i++) sum += ans[i] * power[i];
  if (bad || sum != n) {
    cout << "N0\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < 31; i++) {
    while (ans[i]) {
      cout << power[i] << ' ';
      ans[i]--;
    }
  }
  cout << '\n';
  return 0;
}
