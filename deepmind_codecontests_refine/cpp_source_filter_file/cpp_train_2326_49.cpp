#include <bits/stdc++.h>
using namespace std;
int n, d, a, cnt;
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt += d - a;
  }
  cout << cnt;
}
