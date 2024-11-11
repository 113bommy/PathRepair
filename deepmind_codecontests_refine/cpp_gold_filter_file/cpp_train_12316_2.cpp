#include <bits/stdc++.h>
int check(int num1, int num2);
using namespace std;
int main() {
  int k, l, m, n, d;
  cin >> k;
  cin >> l;
  cin >> m;
  cin >> n;
  cin >> d;
  int total = 0;
  for (int i = 1; i < d + 1; i++) {
    if (check(i, k) || check(i, l) || check(i, m) || check(i, n)) {
      total++;
    }
  }
  cout << total << endl;
  return 0;
}
int check(int num1, int num2) {
  if (num1 % num2 == 0) {
    return 1;
  } else {
    return 0;
  }
}
