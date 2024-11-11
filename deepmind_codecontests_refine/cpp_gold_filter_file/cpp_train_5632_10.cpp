#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int mod = 1 << 30;
int n, k;
int arr[102] = {};
vector<int> ans;
int main() {
  scanf("%d", &n), scanf("%d", &k);
  for (int i = 0; i < (int)(k); ++i) {
    int a;
    scanf("%d", &a);
    arr[a]++;
  }
  for (int i = 0; i < 102; i++)
    if (arr[i]) ans.push_back(arr[i]);
  sort(ans.rbegin(), ans.rend());
  for (int i = 1; i < 102; i++) {
    int res = 0;
    for (int j = 0; j < (int)ans.size(); j++) res += ans[j] / i;
    if (res < n) {
      cout << i - 1;
      return 0;
    }
  }
  return 0;
}
