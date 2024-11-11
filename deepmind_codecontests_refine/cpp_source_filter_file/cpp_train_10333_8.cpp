#include <bits/stdc++.h>
using namespace std;
const int maxn = 1123;
int n, a[maxn];
int f(int k) { return n - k - (n + k - 1) / k + 1; }
void query(int k, int &cur) {
  cout << k;
  int have = 0;
  for (int(i) = (0); (i) <= ((n)-1); (i)++)
    if (!a[i]) {
      cout << ' ' << i + 1;
      a[i] = 1;
      have++, cur++;
      if (have == k) break;
    }
  cout << endl;
  int x;
  cin >> x;
  for (int(i) = (0); (i) <= ((x)-1); (i)++)
    if (a[(x + i - 1) % n] == 1) {
      a[(x + i - 1) % n] = 0;
      cur--;
    }
}
int main() {
  cin >> n;
  int k = 1;
  for (int(i) = (2); (i) <= (n); (i)++)
    if (f(i) > f(k)) k = i;
  for (int i = 0; i < n; i += k) a[i] = -1;
  int cur = 0;
  while (cur < f(k)) query(k, cur);
  cout << 0 << endl;
}
