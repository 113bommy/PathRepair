#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int b[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, k, m;
  cin >> n >> k >> m;
  long long int i;
  for (i = 0; i <= n - 1; i++) {
    cin >> a[i];
    b[a[i] % m] += 1;
  }
  long long int c = -1;
  for (i = 0; i <= 100004; i++) {
    if (b[i] >= k) {
      c = i;
      cout << "Yes\n";
      break;
    }
  }
  if (c != -1) {
    long long int count1 = 0;
    for (i = 0; i <= n - 1; i++) {
      if (a[i] % m == c) {
        cout << a[i] << " ";
        count1++;
      }
      if (count1 == k) {
        return (0);
      }
    }
  }
  cout << "No";
}
