#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, k;
  int a[100000];
  cin >> b;
  cin >> k;
  int flag = 1;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  if (b % 2 == 0) {
    if (a[k - 1] % 2 == 0)
      cout << "even";
    else
      cout << "odd";
  } else {
    for (int i = 0; i < k; i++) {
      if (a[i] % 2 == 1) flag * -1;
    }
    if (flag == -1)
      cout << "odd";
    else
      cout << "even";
  }
}
