#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &k);
  char s[100005];
  scanf("%s", s);
  int m = strlen(s);
  multiset<int> num;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    num.insert(s[i] - '0');
    sum += s[i] - '0';
  }
  int ans = 0;
  while (sum < k) {
    sum += 9 - *num.begin();
    num.erase(num.begin());
    ans++;
  }
  cout << ans << endl;
  return 0;
}
