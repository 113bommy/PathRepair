#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  unsigned long long int A[21];
  unsigned long long int Summ = 0;
  for (int i = 0; i <= 20; ++i) A[i] = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    ++A[k + 10];
  }
  for (int i = 0; i < 10; ++i) Summ = A[i] * A[20 - i];
  for (int i = 1; i < A[10]; ++i) {
    Summ += i;
  }
  cout << Summ;
}
