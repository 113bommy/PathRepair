#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, count1 = 0, count2 = 0, c;
  cin >> n;
  long long A[n];
  for (i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] % 2 == 0)
      count1++;
    else
      count2++;
  }
  c = (count1 > count2 ? count1 : count2);
  cout << (n - c);
  return 0;
}
