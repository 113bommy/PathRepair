#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 10;
long long arr[Maxn];
vector<long long> ans;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  reverse(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] == arr[i + 1]) {
      ans.push_back(arr[i]);
      i++;
    } else if (arr[i] == arr[i + 1] + 1) {
      ans.push_back(arr[i + 1]);
      i++;
    }
  }
  long long s = 0;
  for (int i = 0; i < (int)ans.size() - 1; i += 2) {
    cerr << ans[i] << " * " << ans[i + 1] << endl;
    s = ans[i] * ans[i + 1];
  }
  cout << s;
  return 0;
}
