#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int cnt[maxn];
bool prime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return (n > 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int s;
  while (n--) {
    cin >> s;
    int root = sqrt(s);
    for (int i = 2; i <= root; i++) {
      if (s % i == 0) cnt[i]++;
      while (s % i == 0) s /= i;
    }
    if (s > 1) cnt[s]++;
  }
  cout << *max_element(cnt, cnt + maxn);
  return 0;
}
