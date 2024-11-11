#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
int main() {
  int n = 0;
  int a = 0;
  int k = 0;
  cin >> n;
  bool arr[5000] = {false};
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[a - 1] = true;
  }
  while (arr[k]) {
    k++;
  }
  cout << k + 1;
}
