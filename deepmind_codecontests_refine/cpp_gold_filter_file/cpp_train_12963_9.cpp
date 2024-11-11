#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char p;
  int a, b;
  int dayM[367], dayF[367];
  for (int i = 0; i < 367; i++) {
    dayF[i] = 0;
    dayM[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> p >> a >> b;
    if (p == 'F') {
      for (int j = a; j <= b; j++) {
        dayF[j]++;
      }
    } else {
      for (int j = a; j <= b; j++) {
        dayM[j]++;
      }
    }
  }
  int m = 0;
  for (int i = 0; i < 367; i++) {
    m = max(m, min(dayF[i], dayM[i]));
  }
  m *= 2;
  cout << m;
}
