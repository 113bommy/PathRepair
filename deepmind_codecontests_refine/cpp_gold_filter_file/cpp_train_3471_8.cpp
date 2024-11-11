#include <bits/stdc++.h>
using namespace std;
long long a[100001], t[100001];
bool cmp(long long a, long long b) { return b < a; }
int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  long long b;
  cin >> b;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
    t[i] = a[i];
  }
  sort(a, a + n - 1, cmp);
  long long sum = 0;
  for (int i = 0; i < (int)(k); i++) sum += a[i];
  if (sum <= b)
    cout << n << endl;
  else {
    int ans = n;
    for (int i = 0; i < (int)(n - 1); i++) {
      if (t[i] >= a[k - 1] || sum - a[k - 1] + t[i] > b) {
        ans = i + 1;
        break;
      }
    }
    cout << ans << endl;
  }
  return EXIT_SUCCESS;
}
