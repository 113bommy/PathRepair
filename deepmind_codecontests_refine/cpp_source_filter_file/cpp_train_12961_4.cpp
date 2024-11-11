#include <bits/stdc++.h>
using namespace std;
const int L = 10005;
char arr[L];
int c[L];
int ct;
int main() {
  long long n, m;
  cin >> n >> m;
  while (1) {
    if (!n || !m) {
      if (m == 1 || n == 1) {
        for (int i = 1; i < ct; i++) {
          cout << c[i] << arr[i];
        }
        cout << c[ct] - 1 << arr[ct] << endl;
      } else
        printf("Impossible\n");
      break;
    }
    if (n > m) {
      arr[++ct] = 'A';
      c[ct] = n / m;
      n %= m;
    } else {
      arr[++ct] = 'B';
      c[ct] = m / n;
      m %= n;
    }
  }
  cin >> n;
  return 0;
}
