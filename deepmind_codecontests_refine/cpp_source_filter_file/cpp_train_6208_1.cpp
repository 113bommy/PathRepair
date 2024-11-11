#include <bits/stdc++.h>
using namespace std;
long long kq[100001];
long long a[100001];
long long check[100001];
void output() {
  long long kq2 = 0;
  long long kq1 = 0;
  for (long long i = 1; i <= 3; i++) {
    kq2 = kq2 + kq[i];
  }
  for (long long i = 3; i <= 6; i++) {
    kq1 = kq1 + kq[i];
  }
  if (kq1 == kq2) {
    cout << "YES" << endl;
    exit(0);
  }
}
void dequy(long long i) {
  if (i > 6) {
    output();
  }
  for (long long j = 1; j <= 6; j++) {
    if (check[j] == 0) {
      kq[i] = a[j];
      check[j] = 1;
      dequy(i + 1);
      check[j] = 0;
    }
  }
}
int main() {
  for (long long i = 1; i <= 6; i++) {
    cin >> a[i];
  }
  dequy(1);
  cout << "NO" << endl;
}
