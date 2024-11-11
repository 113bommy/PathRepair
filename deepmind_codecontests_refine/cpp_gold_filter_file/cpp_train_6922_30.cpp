#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[100000];
  int B[100000];
  int na;
  int nb;
  int k;
  int m;
  cin >> na >> nb;
  cin >> k >> m;
  for (int i = 0; i < na; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < nb; i++) {
    cin >> B[i];
  }
  if (A[k - 1] < B[nb - m]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
