#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
bool cmp(int a, int b) { return a >= b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> even, odd;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    if (x & 1)
      odd.push_back(x);
    else
      even.push_back(x);
  }
  sort(even.begin(), even.end(), cmp);
  sort(odd.begin(), odd.end(), cmp);
  int ne = even.size(), no = odd.size();
  if (abs(ne - no) <= 1) {
    cout << 0 << endl;
  } else {
    long long int ans1 = 0, ans2 = 0;
    int i = 0, j = 0, k = 0;
    while (i < even.size() && j < odd.size()) {
      if (k % 2 == 0) {
        ans1 += even[i];
        i++;
        k++;
      } else {
        ans1 += odd[j];
        j++;
        k++;
      }
    }
    if (k % 2 == 0) {
      if (i < even.size()) ans1 += even[i];
    } else {
      if (j < odd.size()) ans1 += odd[j];
    }
    i = 0, j = 0, k = 0;
    while (i < even.size() && j < odd.size()) {
      if (k % 2 == 1) {
        ans2 += even[i];
        i++;
        k++;
      } else {
        ans2 += odd[j];
        j++;
        k++;
      }
    }
    if (k % 2 == 1) {
      if (i < even.size()) ans2 += even[i];
    } else {
      if (j < odd.size()) ans2 += odd[j];
    }
    long long int ans = min(sum - ans1, sum - ans2);
    cout << ans << endl;
  }
  return 0;
}
