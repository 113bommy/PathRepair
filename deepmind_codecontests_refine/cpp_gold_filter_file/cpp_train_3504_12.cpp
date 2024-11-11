#include <bits/stdc++.h>
using namespace std;
const long long BIG = 2e18;
vector<long long> vec[63];
vector<long long> ans;
long long arr[100003];
int main() {
  int n;
  scanf("%d", &n);
  long long curr = BIG;
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  sort(arr, arr + n);
  ans = {arr[0]};
  long long start = arr[0];
  for (int i = 1; i < n; i++) {
    int cnt = 0;
    long long x = 1;
    while (x * 2 <= arr[i]) {
      x *= 2;
      cnt++;
    }
    vec[cnt].push_back(arr[i]);
  }
  bool bol = 1;
  while (bol) {
    bol = 0;
    long long x = 1;
    for (int i = 0; i <= 62; i++) {
      if (vec[i].size() && (x | start) != start) {
        start ^= vec[i].back();
        ans.push_back(vec[i].back());
        vec[i].pop_back();
        bol = 1;
        break;
      }
      x *= 2;
    }
  }
  if (ans.size() == n) {
    printf("Yes\n");
    for (int i = 0; i < ans.size(); i++) {
      printf("%lld", ans[i]);
      if (i != ans.size() - 1) printf(" ");
    }
    printf("\n");
  } else {
    printf("No\n");
  }
}
