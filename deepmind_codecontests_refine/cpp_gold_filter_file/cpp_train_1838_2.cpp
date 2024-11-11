#include <bits/stdc++.h>
using namespace std;
long long int p, pre, k, cnt;
vector<long long int> ans;
int main() {
  scanf("%lld %lld", &p, &k);
  if (p < k) {
    printf("1\n%lld\n", p);
    return 0;
  }
  pre = p;
  while (1) {
    cnt = (k - pre);
    if (cnt <= 0) {
      cnt = cnt / k;
      cnt -= 1;
    } else {
      cnt = cnt / k;
      if (cnt * k == (k - pre)) {
        cnt -= 1;
      }
    }
    pre = cnt;
    if (pre == 0) {
      printf("-1\n");
      return 0;
    }
    ans.push_back(pre);
    if (pre > 0 && pre < k) {
      break;
    }
  }
  reverse(ans.begin(), ans.end());
  pre = p;
  for (int i = ans.size() - 1; i >= 0; i--) {
    long long int temp = ans[i] * k + pre;
    pre = ans[i];
    ans[i] = temp;
  }
  reverse(ans.begin(), ans.end());
  ans.push_back(pre);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
