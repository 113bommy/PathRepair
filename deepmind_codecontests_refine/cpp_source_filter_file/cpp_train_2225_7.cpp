#include <bits/stdc++.h>
using namespace std;
int N, good;
bool prime[100010];
vector<int> fact, num, lis;
int main() {
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i <= 100000; i++)
    if (prime[i])
      for (int j = 2; i * j <= 100000; j++) prime[i * j] = false;
  for (int i = 2; i <= 100000; i++)
    if (prime[i]) {
      num.push_back(i);
      lis.push_back(0);
    }
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &good);
    int temp = good;
    fact.clear();
    int longest = 0;
    for (int i = 0; i < num.size() && num[i] * num[i] <= good; i++)
      if (good % num[i] == 0) {
        fact.push_back(i);
        longest = max(longest, lis[i] + 1);
        while (temp % num[i] == 0) temp /= num[i];
      }
    if (temp > 1) {
      int i = lower_bound(num.begin(), num.end(), temp) - num.begin();
      fact.push_back(i);
      longest = max(longest, lis[i] + 1);
    }
    for (int i = 0; i < fact.size(); i++)
      lis[fact[i]] = max(lis[fact[i]], longest);
  }
  int ans = 0;
  for (int i = 0; i < num.size(); i++) ans = max(ans, lis[i]);
  printf("%d\n", ans);
  return 0;
}
