#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[20], flag(0);
  char name[2000005];
  cin >> n;
  cin >> name;
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (name[i] - '0' < a[name[i] - '0']) {
      name[i] = a[name[i] - '0'] + '0';
      flag = 2;
    } else if (name[i] - '0' > a[name[i] - '0'] && flag == 2)
      break;
  }
  cout << name;
  return 0;
}
