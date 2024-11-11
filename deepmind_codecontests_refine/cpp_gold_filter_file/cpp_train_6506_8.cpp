#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k = 1, l2 = 0;
  string str;
  cin >> n >> m >> str;
  for (int i = 1; i < n; i++)
    if (str[i] != str[i - 1]) k++;
  int i = 0;
  while (i < n - 1) {
    if (str[i] != str[i + 1]) {
      long long j = i;
      while (i + 2 < n && str[i + 2] == str[i]) i++;
      j = (i - j) + 2;
      l2 += j * (j - 1) / 2;
    }
    i++;
  }
  cout << k * (m * n - n) - l2 << endl;
}
