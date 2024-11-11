#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, M[25] = {}, a, answ = 0;
  scanf("%I64d", &n);
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a);
    M[a + 10]++;
  }
  answ = M[0 + 10] * (M[0 + 10] - 1) / 2;
  for (int i = 1; i <= 10; i++) answ += M[10 - i] * M[i + 10];
  cout << answ << endl;
  return 0;
}
