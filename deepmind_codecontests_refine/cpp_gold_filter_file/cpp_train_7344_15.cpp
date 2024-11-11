#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d;
  int a[100000 + 10];
  cin >> n >> b >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  int p = 0, emp = 0;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b) continue;
    temp += a[i];
    if (temp > d) {
      emp++;
      temp = 0;
    }
  }
  cout << emp;
}
