#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
long long int A[2100];
int main() {
  int n;
  cin >> n;
  int flag = -1;
  long long int s;
  long long int count1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (i != 0) {
      s = gcd(A[i], A[i - 1]);
      if (s == 1) flag = 1;
    }
    if (A[i] == 1) {
      count1++;
      flag = 1;
    }
  }
  if (flag == 1) {
    cout << n - count1 << endl;
  } else {
    long long int minL = INT_MAX;
    for (int i = 0; i < n; i++) {
      int g = A[i];
      for (int j = i + 1; j < n; j++) {
        g = gcd(A[j], A[i]);
        if (g == 1) {
          int len = j - i + 1;
          if (len < minL) minL = len;
        }
      }
    }
    if (minL >= INT_MAX)
      cout << "-1" << endl;
    else
      cout << (minL - 2 + n) << endl;
  }
}
