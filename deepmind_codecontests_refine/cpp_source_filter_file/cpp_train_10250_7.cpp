#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  long long n, k;
  while (cin >> n >> k) {
    long long sum = 0;
    char a[100010];
    int i = 0;
    int num[30] = {0};
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) num[a[i] - 'A']++;
    sort(num, num + 26, cmp);
    for (int i = 0; i < 26; i++) {
      if (!num[i]) break;
      if (k > num[i]) {
        sum += num[i] * num[i];
        k -= num[i];
      } else {
        sum += k * k;
        k = 0;
      }
      if (k <= 0) break;
    }
    cout << sum << endl;
  }
}
