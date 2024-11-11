#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(NULL);
  cout.tie(NULL);
  cin.tie(NULL);
}
const double pi = 2 * acos(0.0);
const long long oo = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int nn = 2e2 + 15;
int dx[8] = {-1, 0, 0, 1, 1, -1, 1, -1};
int dy[8] = {0, -1, 1, 0, 1, -1, -1, 1};
int main() {
  fast();
  int n;
  cin >> n;
  int arr[nn][nn];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  }
  long long sum = 0;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    if (!mp[make_pair(i, i)]) {
      sum += arr[i][i];
      mp[make_pair(i, i)]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!mp[make_pair(i, n - i - 1)]) {
      sum += arr[i][n - i - 1];
      mp[make_pair(i, n - i - 1)]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!mp[make_pair(n / 2, i)]) {
      sum += arr[n / 2][i];
      mp[make_pair((n) / 2, i)]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!mp[make_pair(i, (n) / 2)]) {
      sum += arr[i][(n) / 2];
      mp[make_pair(i, (n) / 2)]++;
    }
  }
  cout << sum << "\n";
  return 0;
}
