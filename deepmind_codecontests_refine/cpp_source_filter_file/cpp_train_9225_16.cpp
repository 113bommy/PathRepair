#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
map<int, int> bus;
int a[maxn];
int num[maxn], Stack[maxn];
int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = false;
    for (int i = 1; i < n; i++)
      if (a[i] != a[i - 1]) {
        flag = true;
        break;
      }
    if (!flag) {
      cout << n * m % k << endl;
      continue;
    }
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++) {
      Stack[++cnt] = a[i];
      if (cnt > 1 && Stack[cnt] == Stack[cnt - 1])
        num[cnt] = num[cnt - 1] + 1;
      else
        num[cnt] = 1;
      if (num[cnt] >= k) cnt -= k;
    }
    long long left = 1, right = cnt;
    long long ans = 0;
    while (left < right && Stack[left] == Stack[right]) {
      long long l = left, r = right, tol = 0;
      while (Stack[l] == Stack[left] && l < r && tol < k) tol++, l++;
      while (Stack[r] == Stack[right] && l < r && tol < k) tol++, r--;
      if (tol == k) {
        left = l;
        right = r;
        ans += k;
      } else
        break;
    }
    flag = false;
    for (long long i = left; i <= right; i++) {
      if (Stack[i] != Stack[i - 1]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      long long mid = (right - left + 1) * m % k;
      if (mid)
        cout << mid + ans << endl;
      else
        cout << 0 << endl;
    } else
      cout << (right - left + 1) * m + ans << endl;
  }
  return 0;
}
