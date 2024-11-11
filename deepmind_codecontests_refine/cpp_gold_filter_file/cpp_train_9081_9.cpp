#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 30;
const double eps = 1e-6;
const double pi = acos(-1.0);
int n;
long long a[maxn], b[maxn];
vector<char> ans;
long long sum1 = 0;
long long sum2 = 0;
void print() {
  if (sum2 <= 2e5)
    puts("SMALL"), printf("%lld", sum1 + sum2), puts("");
  else
    puts("BIG"), printf("%lld", sum2), puts("");
  if (sum2 > 2e5) return;
  for (auto it = ans.rbegin(); it != ans.rend(); it++) printf("%c", *it);
  puts("");
}
bool increase() {
  for (int i = 1; i <= n - 1; i++)
    if (b[i] >= b[i + 1]) return 0;
  for (int i = 1; i <= n; i++)
    if (b[i] <= 0) return 0;
  return 1;
}
bool decrease() {
  for (int i = 1; i <= n - 1; i++)
    if (b[i] <= b[i + 1]) return 0;
  for (int i = 1; i <= n; i++)
    if (b[i] <= 0) return 0;
  return 1;
}
bool equal() {
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) return 0;
  return 1;
}
bool equal_rev() {
  for (int i = 1; i <= n; i++)
    if (a[i] != b[n + 1 - i]) return 0;
  return 1;
}
void rollback() {
  for (int i = n; i >= 2; i--) b[i] -= b[i - 1];
}
void rev() { reverse(b + 1, b + n + 1); }
void solve() {
  while (1) {
    if (equal()) {
      print();
      break;
    } else if (equal_rev()) {
      sum1++, ans.push_back('R'), print();
      break;
    } else if (increase())
      rollback(), sum2++, ans.push_back('P');
    else if (decrease())
      rev(), sum1++, ans.push_back('R');
    else {
      puts("IMPOSSIBLE");
      break;
    }
  }
}
void push(long long x) {
  sum2 += x;
  int now = ans.size();
  while (now <= 2e5 && x--) now++, ans.push_back('P');
}
void cal() {
  long long min1 = a[1], max1 = a[2];
  if (min1 > max1) swap(min1, max1);
  while (1) {
    if (equal()) {
      print();
      break;
    } else if (equal_rev()) {
      sum1++, ans.push_back('R'), print();
      break;
    } else if (increase()) {
      long long x = 0;
      if (b[1] == min1) {
        if ((b[2] - max1) % b[1] == 0) {
          x = (b[2] - max1) / b[1], push(x);
          if (min1 != a[1]) sum1++, ans.push_back('R');
          print();
          return;
        } else {
          puts("IMPOSSIBLE");
          return;
        }
      } else {
        x = b[2] / b[1];
        b[2] %= b[1];
        push(x);
      }
    } else if (decrease())
      rev(), sum1++, ans.push_back('R');
    else {
      puts("IMPOSSIBLE");
      break;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  if (n == 1) {
    if (a[1] == b[1])
      printf("SMALL\n0\n"), puts("");
    else
      puts("IMPOSSIBLE");
  } else if (n == 2)
    cal();
  else
    solve();
  return 0;
}
