#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int solve(const string& temp, char k) {
  int cnt = 0, sum = temp.size();
  if (sum == 1) return temp[0] != k;
  int mid = sum / 2;
  int sum1 = 0, sum2 = 0;
  sum1 = solve(string(temp.begin(), temp.begin() + mid), k + 1);
  sum2 = solve(string(temp.begin() + mid, temp.end()), k + 1);
  for (auto t : s) {
    cnt++;
    if (cnt <= mid && t != k) sum2++;
    if (cnt > mid && t != k) sum1++;
  }
  return min(sum1, sum2);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    cout << solve(s, 'a') << endl;
  }
  return 0;
}
