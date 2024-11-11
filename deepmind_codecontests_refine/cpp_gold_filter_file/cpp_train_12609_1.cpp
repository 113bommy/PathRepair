#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e5;
long long ans = 0;
int N, K;
string str1, str2;
int main() {
  cin >> N >> K;
  cin >> str1 >> str2;
  if (K == 1) {
    printf("%d\n", N);
    return 0;
  }
  int i = 0, cnt = 0;
  K -= 2;
  while (i < N && str1[i] == str2[i]) i++, ans++;
  if (i < N) i++, ans += 2;
  while (i < N) {
    int t = min(cnt, K);
    cnt += t;
    K -= t;
    if (str1[i] == 'a' && K) cnt++, K--;
    if (str2[i] == 'b' && K) cnt++, K--;
    ans += cnt + 2;
    i++;
  }
  printf("%lld\n", ans);
}
