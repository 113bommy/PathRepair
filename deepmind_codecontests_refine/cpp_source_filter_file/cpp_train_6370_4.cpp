#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int candies[4];
  int sum = 0;
  bool exist = false;
  int maxv = 0;
  for (int i = 0; i < 4; i++) {
    cin >> candies[i];
    sum += candies[i];
    if (maxv < candies[i]) maxv = candies[i];
  }
  if (sum % 2 == 0) {
    if (sum - maxv == sum / 2) exist = true;
    for (int i = 1; i < 3; i++) {
      if (candies[0] + candies[i] == sum / 2) exist = true;
    }
  }
  if (exist)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
