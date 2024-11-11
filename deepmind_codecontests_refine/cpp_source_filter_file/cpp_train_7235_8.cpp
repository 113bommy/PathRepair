#include <bits/stdc++.h>
using namespace std;
int num[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  int ans = abs(num[0]);
  int temp = num[0];
  for (int i = 1; i < n; i++) {
    ans += abs(num[i] - temp);
    temp = num[i];
  }
  cout << ans << endl;
}
