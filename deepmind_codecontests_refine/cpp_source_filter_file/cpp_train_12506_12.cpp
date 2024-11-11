#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
long long int ceil_div(long long int a, long long int b) {
  return (a + b - 1) / b;
}
void fun() {
  int a, b, n, i, j, x, nb, q, k;
  cin >> n;
  string str;
  cin >> str;
  if (n == 2) {
    if (str[0] <= str[1]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << "2" << endl;
      cout << str[0] << " " << str[1] << endl;
    }
  } else {
    cout << "YES" << endl;
    cout << "2" << endl;
    cout << str[0] << " ";
    for (i = 1; i < n; i++) {
      cout << str[i];
    }
    cout << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    fun();
  }
}
