#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e6 + 10;
int a[maxi];
string s;
int n, k;
int p[maxi];
int bit[maxi];
int inv[maxi];
int cnt[maxi];
long long bit1[maxi];
void update(int x, int poz) {
  for (int i = poz; i < maxi; i += i & -i) bit[i] += x;
}
void update1(int x, int poz) {
  for (int i = poz; i < maxi; i += i & -i) bit1[i] += x;
}
int get1(int poz) {
  long long ans = 0;
  for (int i = poz; i > 0; i -= i & -i) ans += bit1[i];
  return ans;
}
int get(int poz) {
  int ans = 0;
  for (int i = poz; i > 0; i -= i & -i) ans += bit[i];
  return ans;
}
long long find(long long x, long long y) {
  long long sum1 = x * (x + 1) / 2;
  long long sum2 = (x - y) * (x - y + 1) / 2;
  return sum1 - sum2;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    cnt[p[i]] = i;
  }
  long long invSum = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0;
    int r = n + 1;
    int trazi = i / 2 + 1;
    invSum += i - get(cnt[i]) - 1;
    update(1, cnt[i]);
    update1(cnt[i], cnt[i]);
    while (l < r - 1) {
      int mid = l + r >> 1;
      if (get(mid) < trazi)
        l = mid;
      else
        r = mid;
    }
    l++;
    long long sum = find(l, trazi) - 2 * get1(l) + invSum + get1(n) -
                    find(l + i - trazi, i - trazi);
    printf("%lld ", sum);
  }
  return 0;
}
