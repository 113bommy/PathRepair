#include <bits/stdc++.h>
using namespace std;
int hashPower = 31;
float pi = 3.141593;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b % 2) res = (res * a) % 1000000007;
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return res;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string first, second;
    cin >> first;
    cin >> second;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      if (first[i] == '0') {
        a[i] = 0;
      } else {
        a[i] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (second[i] == '0') {
        b[i] = 0;
      } else {
        b[i] = 1;
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        if (a[i] == 0) {
          count++;
          a[i] = 2;
        } else {
          if (a[i - 1] == 1 && (i - 1 >= 0)) {
            count++;
            a[i - 1] = 2;
          } else if (a[i + 1] == 1 && (i + 1 < n)) {
            count++;
            a[i + 1] = 2;
          }
        }
      }
    }
    cout << count << endl;
  }
}
