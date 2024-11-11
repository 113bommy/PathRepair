#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, num;
  char a[105];
  cin >> n;
  cin.ignore();
  while (n > 0) {
    i = 0;
    num = 0;
    cin.getline(a, 105);
    while (a[i] <= 'z' && a[i] >= 'a') {
      num++;
      i++;
    }
    if (num > 10) {
      cout << a[0] << num - 2 << a[i - 1];
    } else {
      for (j = 0; j < i; j++) cout << a[j];
    }
    cout << endl;
    n--;
  }
  return 0;
}
