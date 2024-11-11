#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
inline long long int modpw(long long int x, long long int y, long long int z) {
  long long int res = 1;
  x = x % z;
  while (y) {
    if (y & 1) res = (res * x) % z;
    x = (x * x) % z;
    y /= 2;
  }
  return res;
}
vector<pair<int, int>> arr(105);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += arr[i].first;
  sort(arr.begin() + 1, arr.begin() + n);
  int temp = arr[0].first;
  int ans[105];
  int id = 0;
  ans[0] = arr[0].second + 1;
  for (int i = 1; i < n; i++)
    if (2 * arr[i].first <= arr[0].first) {
      temp += arr[i].first;
      ans[++id] = arr[i].second + 1;
    }
  if (temp > sum / 2) {
    cout << id + 1 << endl;
    for (int i = 0; i <= id; i++) cout << ans[i] << " ";
  } else {
    cout << 0 << endl;
  }
}
