#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  vector<int> arr[100001];
  int idx = -1;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d", &temp);
    arr[temp % m].push_back(temp);
    if (arr[temp % m].size() >= k) {
      idx = temp % m;
      break;
    }
  }
  if (idx != -1) {
    printf("Yes\n");
    sort(arr[idx].begin(), arr[idx].end());
    for (int i = 0; i < arr[idx].size(); ++i) printf("%d ", arr[idx][i]);
  } else {
    printf("No\n");
  }
  return 0;
}
