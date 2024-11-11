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
  for (int i = 0; i < (int)(101); ++i)
    if (arr[i]) ans.push_back(arr[i]);
  for (int day = 1; day <= 101; day++) {
    int mx = 0;
    for (int i = 0; i < (int)ans.size(); i++) mx += ans[i] / day;
    if (mx < n) {
      printf("%d\n", day - 1);
      return 0;
    }
  }
  return 0;
}
