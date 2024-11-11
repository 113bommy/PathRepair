#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long v[5 + N];
long long rez[5 + N];
int main() {
  long long n, m, i;
  cin >> n >> m;
  for (i = 1; i <= m; i++) cin >> v[i];
  for (i = 1; i < m; i++) {
    long long num1, num2;
    num1 = v[i];
    num2 = v[i + 1];
    if (num1 != num2) {
      if (num1 > num2) swap(num1, num2);
      rez[1] += num2 - num1;
      rez[num1] -= num2 - num1;
      rez[num1] += num2 - 1;
      rez[num1 + 1] -= num2 - 1;
      rez[num1 + 1] += num2 - num1 - 1;
      rez[num2] -= num2 - num1 - 1;
      rez[num2] += num1;
      rez[num2 + 1] -= num1;
      rez[num2 + 1] += num2 - num1;
    }
  }
  for (i = 1; i <= m; i++) rez[i] += rez[i - 1];
  for (i = 1; i <= n; i++) cout << rez[i] << " ";
  return 0;
}
