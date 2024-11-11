#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
long long cnt_max, num[maxn], n, the_num;
map<long long, long long> cnt;
map<long long, long long> dcnt;
int read() {
  int res = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 1) + (res << 3) + ch - '0';
    ch = getchar();
  }
  return res;
}
bool Solve() {
  n = read();
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    num[i] = read();
  }
  sort(num + 1, num + 1 + n);
  for (int i = 1; i <= n; i++) {
    sum += num[i];
    dcnt[num[i] - num[i - 1]]++;
    if (cnt[num[i]] == 1 && cnt_max == 2) return false;
    cnt[num[i]]++;
    cnt_max = max(cnt_max, cnt[num[i]]);
    if (cnt[num[i]] == 2) the_num = num[i];
  }
  if (n == 1) {
    if (num[1] == 0 || num[1] % 2 == 0) return false;
    return true;
  } else if (n == 2) {
    if (sum <= 1) return false;
    if (num[1] == num[2]) return true;
    if ((num[1] + num[2]) % 2) return false;
    return true;
  } else {
    if (sum <= 1) return false;
    if (cnt_max >= 3) return false;
    if (cnt_max == 2) {
      if (cnt[0] == 2) return false;
      if (cnt[the_num - 1]) return false;
    }
    long long temp = sum - n * (n - 1) / 2;
    if (temp % 2) return true;
    return false;
  }
  if (rand() % 2) return true;
  return false;
}
int main() {
  {
    bool flag = Solve();
    if (flag == 0)
      cout << "cslnb\n";
    else
      cout << "sjfnb\n";
  }
  return 0;
}
