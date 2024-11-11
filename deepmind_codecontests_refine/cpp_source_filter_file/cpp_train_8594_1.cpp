#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
char ar[MAXN];
vector<long long> s[2];
long long tree[MAXN][2];
long long n;
int read(int k, int i) {
  long long sum = 0;
  while (k > 0) {
    sum += tree[k][i];
    k -= k & -k;
  }
  return sum;
}
void add(int k, long long num, int i) {
  while (k <= n) {
    tree[k][i] += num;
    k += k & -k;
  }
}
int main() {
  cin >> n;
  scanf("%s", ar + 1);
  s[0].push_back(0);
  s[1].push_back(0);
  int lenu = 1, lend = 1;
  for (int i = 1; i <= n; i++) {
    if (ar[i] == 'D') {
      s[1].push_back(i);
      add(lend++, i, 1);
    } else {
      s[0].push_back(i);
      add(lenu++, i, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    int up = lower_bound(s[0].begin(), s[0].end(), i) - s[0].begin();
    int down = lower_bound(s[1].begin(), s[1].end(), i) - s[1].begin();
    if (up == s[0].size()) up--;
    int cur = i;
    if (ar[i] == 'U') {
      up--;
      int len = min(up, lend - down);
      ans += (-read(up, 0) + read(up - len, 0) + read(down + len - 1, 1) -
              read(down - 1, 1)) *
             2;
      if (lend - down <= up)
        ans += (n - cur + 1);
      else
        ans += (s[1][down + len] * 2 - cur);
    } else {
      down++;
      while (up >= 0 && s[0][up] > cur) up--;
      int len = min(up, lend - down);
      ans += (-read(up, 0) + read(up - len, 0) + read(down + len - 1, 1) -
              read(down - 1, 1)) *
             2;
      if (lend - down >= up)
        ans += cur;
      else
        ans += (cur - s[0][up - len] + n + 1 - s[0][up - len]);
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
