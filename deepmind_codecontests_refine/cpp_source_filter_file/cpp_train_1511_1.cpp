#include <bits/stdc++.h>
using namespace std;
int ans = 0, count1[1100000], n, temp;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    count1[temp]++;
  }
  for (int i = 0; i <= 1000000; i++) {
    if (count1[i] == 0) continue;
    ans += (count1[i] % 2);
    count1[i + 1] += (count1[i] / 2);
  }
  cout << ans << "\n";
}
