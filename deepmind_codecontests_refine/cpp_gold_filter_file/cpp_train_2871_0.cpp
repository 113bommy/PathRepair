#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v;
int main() {
  long long int n, num, i;
  cin >> n;
  long int a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> num;
    a[i] = num;
  }
  if (n % 2 == 0) {
    for (i = 1; i <= n; i++) {
      if (i % 2 == 0 && i <= n / 2 || i % 2 != 0 && i > n / 2) {
        cout << a[i] << " ";
      } else
        cout << a[n - i + 1] << " ";
    }
  } else {
    for (i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        cout << a[i] << " ";
      } else
        cout << a[n - i + 1] << " ";
    }
  }
}
