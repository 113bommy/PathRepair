#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y;
vector<long long> vec;
int a[10001];
stringstream s;
string str1, str2;
int main() {
  cin >> n >> x >> y;
  int i = 1;
  bool f = false;
  if (y < n) {
    cout << "-1\n";
    return 0;
  }
  i = y - n + 1;
  if (i * i + n - 1 >= x) {
    cout << i << endl;
    for (i = 0; i < n - 1; i++) printf("1\n");
    return 0;
  }
  if (y % n != 0) {
    if ((y / n) * (y / n) * (n - 1) + (y % n) * (y % n) >= x) {
      for (int i = 1; i < n; i++) cout << y / n << " ";
      cout << y % n << endl;
      return 0;
    }
  } else if ((y / n) * (y / n) * n >= x) {
    for (int i = 1; i <= n; i++) cout << y / n << " ";
    cout << endl;
    return 0;
  }
  if (!f) {
    cout << "-1" << endl;
    return 0;
  }
  return 0;
}
