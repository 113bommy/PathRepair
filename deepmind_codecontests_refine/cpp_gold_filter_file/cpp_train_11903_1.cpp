#include <bits/stdc++.h>
using namespace std;
vector<long long int> pos;
int main() {
  int k;
  string X;
  scanf("%d", &k);
  cin >> X;
  for (int i = 0; i < X.length(); i++) {
    if (X[i] == '1') pos.push_back(i);
  }
  int n = pos.size();
  if (n < k) {
    cout << "0";
    return 0;
  }
  if (k == 0) {
    long long int ans = 0;
    long long int left = -1, right = -1;
    for (int i = 0; i < X.length(); i++) {
      if ((X[i] == '1') && (left != -1)) {
        right = i;
        long long int len = right - left + 1 - 2;
        ans += (len * (len + 1)) / 2;
        left = right;
      } else if ((X[i] == '1') && (left == -1)) {
        left = i;
        long long int len = (left - 1 - 0 + 1);
        ans += (len * (len + 1)) / 2;
      } else if (i == X.length() - 1) {
        right = i;
        long long int len = right - left + 1 - 1;
        ans += (len * (len + 1)) / 2;
        left = right;
      }
    }
    cout << ans;
    return 0;
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((i + k - 1) >= n) break;
    if ((i == 0) && (i + k - 1 == n - 1)) {
      ans += (pos[i] - 0 + 1) * (X.length() - 1 - pos[i + k - 1] + 1);
    } else if (i == 0) {
      ans += (pos[i] - 0 + 1) * (pos[i + k] - 1 - pos[i + k - 1] + 1);
    } else if (i + k - 1 == n - 1) {
      ans +=
          (pos[i] - pos[i - 1] - 1 + 1) * (X.length() - 1 - pos[i + k - 1] + 1);
    } else {
      ans +=
          (pos[i] - pos[i - 1] - 1 + 1) * (pos[i + k] - 1 - pos[i + k - 1] + 1);
    }
  }
  cout << ans;
  return 0;
}
