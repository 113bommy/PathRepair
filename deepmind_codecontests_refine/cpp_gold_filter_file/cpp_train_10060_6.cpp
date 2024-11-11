#include <bits/stdc++.h>
using namespace std;
long long b[100010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, i, best = 1e10, bestans = 1, num, l1 = -1, l2 = -1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> num;
    if (num > l1) {
      b[num] = 1;
      l2 = l1;
      l1 = num;
    } else if (num > l2) {
      b[l1]--;
      l2 = num;
    }
  }
  for (i = 1; i <= n; i++)
    if (b[i] < b[bestans]) bestans = i;
  cout << bestans << endl;
  return 0;
}
