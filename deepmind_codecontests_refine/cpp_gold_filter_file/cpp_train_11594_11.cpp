#include <bits/stdc++.h>
using namespace std;
const int inf = 0;
const double eps = 0;
const int ms = 0;
const int md = 0;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(0);
  arr.push_back(1);
  arr.push_back(1);
  long long a = k + 1;
  while (1) {
    a++;
    long long aux = a - k;
    long long tmp = arr[aux - 1] * 2;
    if (aux > k) {
      tmp -= arr[aux - 1 - k];
    }
    if (tmp <= n)
      arr.push_back(tmp);
    else
      break;
  }
  vector<long long> ans;
  for (int i = arr.size() - 1; i >= 0; i--) {
    if (!ans.size() && n == arr[i]) {
      ans.push_back(0);
      ans.push_back(arr[i]);
      break;
    }
    if (arr[i] <= n) {
      ans.push_back(arr[i]);
      n -= arr[i];
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
