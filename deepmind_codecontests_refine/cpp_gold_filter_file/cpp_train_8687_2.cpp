#include <bits/stdc++.h>
using namespace std;
int n;
int jrr[21];
void bin(long long m) {
  for (int i = 19; i >= 0; i--) {
    jrr[i] = 0;
    jrr[20] = 0;
    jrr[i] = m % 10;
    m = m / 10;
  }
}
long long binary(long long num) {
  long long binary = 0;
  long long i = 1;
  int rem;
  while (num != 0) {
    rem = num % 2;
    num = num / 2;
    binary = binary + rem * i;
    i = i * 10;
  }
  return binary;
}
int main() {
  int g = 0, h = 0;
  int news[1002][21];
  int m, k;
  long long arr[1002];
  cin >> n >> m >> k;
  for (int i = 0; i < m + 1; i++) {
    cin >> arr[i];
    arr[i] = binary(arr[i]);
    bin(arr[i]);
    for (int z = 0; z < 20; z++) news[i][z] = jrr[z];
  }
  for (int j = 0; j < m; j++) {
    g = 0;
    for (int y = 0; y < 20; y++) {
      if (news[m][y] != news[j][y]) {
        g++;
      }
    }
    if (g <= k) h++;
  }
  cout << h;
  return 0;
}
