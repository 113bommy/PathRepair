#include <bits/stdc++.h>
using namespace std;
const int INF = 300000;
int A[300000];
int main() {
  for (int i = 0; i < 300000; i++) A[i] = INF;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    A[x] = i;
  }
  int k = 0;
  for (int i = 1; i < 300000; i++)
    if (A[i] < A[k]) k = i;
  cout << k;
  return 0;
}
