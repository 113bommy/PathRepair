#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n + 1];
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    long long m;
    cin >> m;
    if (m % 2 == 0) {
      flag = 1;
    }
    if (flag == 1)
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
}
