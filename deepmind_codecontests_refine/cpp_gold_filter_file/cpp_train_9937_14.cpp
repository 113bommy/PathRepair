#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int m, n;
  cin >> m >> n;
  vector<int> A(m), B(n);
  for (int i = (0); i <= ((int)(A).size() - 1); ++i) cin >> A[i];
  for (int i = (0); i <= ((int)(B).size() - 1); ++i) cin >> B[i];
  int max_a = 0, max_b = 0;
  for (int i = (0); i <= ((int)(A).size() - 1); ++i)
    max_a = (((max_a) > (A[i])) ? (max_a) : (A[i]));
  for (int i = (0); i <= ((int)(B).size() - 1); ++i)
    max_b = (((max_b) > (B[i])) ? (max_b) : (B[i]));
  if (max_a > max_b) {
    swap(A, B);
    swap(m, n);
    swap(max_a, max_b);
  }
  long long int cost = 0, sum_a = 0;
  for (int i = (0); i <= ((int)(A).size() - 1); ++i) sum_a += A[i];
  cost = sum_a;
  for (int i = (0); i <= ((int)(B).size() - 1); ++i)
    if (B[i] == max_b) {
      B.erase(B.begin() + i);
      break;
    }
  for (int i = (0); i <= ((int)(B).size() - 1); ++i)
    cost += (((B[i]) < (sum_a)) ? (B[i]) : (sum_a));
  cout << cost;
  return 0;
}
