#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  vector<long long int> ans;
  for (long long int j = 0; j < t; j++) {
    long long s, r;
    cin >> s;
    r = s;
    if (s < 10)
      ans.push_back(s);
    else {
      long long sum = 0;
      while (r >= 10) {
        long long temp;
        temp = r / 10;
        sum = sum + temp * 10;
        r = temp + r % 10;
      }
      sum = sum + r;
      ans.push_back(sum);
    }
  }
  for (long long int j = 0; j < t; j++) {
    cout << ans[j] << endl;
  }
}
