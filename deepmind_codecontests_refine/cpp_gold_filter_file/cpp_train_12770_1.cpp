#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  char arr[50][50];
  cout << 50 << " " << 50 << endl;
  for (long long i = 0; i < 25; i++) {
    for (long long j = 0; j < 50; j++) {
      arr[i][j] = 'A';
    }
  }
  long long i = 0;
  long long j = 0;
  while (b > 0) {
    if (j >= 50) {
      j = j - 50;
      i = i + 2;
    }
    arr[i][j] = 'B';
    j = j + 2;
    b--;
  }
  while (c > 0) {
    if (j >= 50) {
      j = j - 50;
      i = i + 2;
    }
    arr[i][j] = 'C';
    j = j + 2;
    c--;
  }
  while (d > 1) {
    if (j >= 50) {
      j = j - 50;
      i = i + 2;
    }
    arr[i][j] = 'D';
    j = j + 2;
    d--;
  }
  for (long long i = 25; i < 50; i++) {
    for (long long j = 0; j < 50; j++) {
      arr[i][j] = 'D';
    }
  }
  i = 26;
  j = 0;
  while (a > 1) {
    if (j >= 50) {
      j = j - 50;
      i = i + 2;
    }
    arr[i][j] = 'A';
    j = j + 2;
    a--;
  }
  for (long long i = 0; i < 50; i++) {
    for (long long j = 0; j < 50; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}
