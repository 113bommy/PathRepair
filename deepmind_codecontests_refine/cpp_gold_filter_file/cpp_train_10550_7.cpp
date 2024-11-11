#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long j;
  if (n > 1000000)
    j = n / 100;
  else if (n > 250)
    j = n / 8;
  else if (n > 20)
    j = n / 4;
  else
    j = n;
  for (long long i = 1; i <= j && j > 1;) {
    if (i * (i + 1) + j * (j - 1) == 2 * n) {
      cout << "YES";
      return 0;
    } else if (i * (i + 1) + j * (j - 1) < 2 * n)
      i++;
    else if (i * (i + 1) + j * (j - 1) > 2 * n)
      j--;
  }
  cout << "NO";
  return 0;
}
