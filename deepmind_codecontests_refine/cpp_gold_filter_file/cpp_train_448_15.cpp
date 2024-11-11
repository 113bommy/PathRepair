#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  long long mov = 0;
  int p = log(n) / log(2);
  for (int i = 0; i < n - 1; ++i) {
    while (n - 1 < i + pow(2, p)) p--;
    mov += A[i];
    long long aux = i + pow(2, p);
    A[aux] += A[i];
    cout << mov << endl;
  }
  return 0;
}
