#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  long long int n, i, j, k = 0, x;
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < i; j++) {
      x = i ^ j;
      if (x <= n && i + x > j && i + j > x && j + x > i) k++;
    }
  }
  cout << k;
}
