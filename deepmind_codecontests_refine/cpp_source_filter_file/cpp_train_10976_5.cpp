#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ct;
  cin >> n >> k;
  while (n--) {
    int tmp;
    cin >> tmp;
    if (tmp <= 5 - k) ct++;
  }
  cout << ct / 3;
}
