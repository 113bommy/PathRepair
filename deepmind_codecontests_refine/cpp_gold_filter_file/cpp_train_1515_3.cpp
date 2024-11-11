#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int, greater<int> > count;
  int a, sum = 0, ans = 600;
  for (int i = 0; i < 5; i++) {
    cin >> a;
    count[a]++;
    sum += a;
  }
  int temp_sum = sum;
  map<int, int>::iterator it;
  for (it = count.begin(); it != count.end(); it++) {
    if (it->second >= 2) {
      if (it->second < 4) {
        sum -= (it->first) * (it->second);
        if (sum < ans) ans = sum;
      } else {
        sum -= (it->first) * 3;
        if (sum < ans) ans = sum;
      }
    }
    sum = temp_sum;
  }
  if (ans == 600) {
    cout << sum;
    exit(0);
  }
  cout << ans;
}
