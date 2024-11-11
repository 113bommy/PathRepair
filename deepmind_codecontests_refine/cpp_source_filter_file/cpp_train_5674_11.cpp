#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cand(n);
  for (int i = 0; i < m; ++i) {
    int* A = new int[n];
    int max = 0;
    for (int j = 0; j < n; ++j) {
      cin >> A[j];
      if (A[j] > A[max]) {
        max = j;
      }
    }
    cand[max] += A[max];
  }
  int max = 0;
  for (int i = 0; i < n; ++i) {
    if (cand[i] > cand[max]) {
      max = i;
    }
  }
  cout << max + 1;
  return 0;
}
