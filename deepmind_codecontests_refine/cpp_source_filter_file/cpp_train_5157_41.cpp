#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  pair<long long, long long> A[n + 1];
  for (int i = 0; i <= n; i++) {
    cin >> A[i].first >> A[i].second;
  }
  long long counter = 0;
  for (int i = 2; i < n; i++) {
    long long x1 = A[i].first;
    long long y1 = A[i].second;
    long long x2 = A[i - 1].first;
    long long y2 = A[i - 1].second;
    long long x3 = A[i + 1].first;
    long long y3 = A[i + 1].second;
    if (y1 == y2 && x1 > x2 && x3 == x1 && y3 > y1) {
      counter++;
    } else if (x1 == x2 && y2 > y1 && y1 == y3 && x3 > x1) {
      counter++;
    } else if (y1 == y2 && x2 > x1 && x1 == x3 && y1 > y3) {
      counter++;
    } else if (x1 == x2 && y1 > y2 && y1 == y3 && x1 > x3) {
      counter++;
    }
  }
  cout << counter;
  return 0;
}
