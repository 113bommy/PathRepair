#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, k;
  int t;
  cin >> t;
  vector<long long int> answer(t, 0);
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> k;
    long long int ans = 0;
    if (k % 2 == 0)
      ans += (a - b) * (k / 2);
    else
      ans += ((a - b) * (k / 2)) + a;
    answer[i] = ans;
  }
  for (int i = 0; i < t; i++) cout << answer.at(i) << endl;
}
