#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int n, day;
long long val[maxn], a[maxn], sum;
map<long long, int> mp;
map<long long, int>::reverse_iterator cur, pre;
int main() {
  cin >> n >> day >> sum;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    a[i] = val[i];
    if (i != n) mp[val[i]]++;
  }
  if (n == 1) {
    cout << n << endl;
    return 0;
  }
  pre = mp.rbegin();
  cur = ++pre;
  while (cur != mp.rend()) {
    (*cur).second += (*pre).second;
    pre = cur;
    ++cur;
  }
  sort(a + 1, a + n);
  long long mxk = 0;
  for (int i = 0; i < day - 1; i++) mxk += a[n - 1 - i];
  for (int i = 1; i < n; i++) {
    int tmp = mp[val[i]];
    long long money = mxk + val[i];
    if (tmp < day) money += (a[n - day + 1] - val[i]);
    if (money > sum) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}
