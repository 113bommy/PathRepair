#include <bits/stdc++.h>
using namespace std;
pair<int, int> A[1000000];
long long a, b;
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A, A + a + 1);
  for (int i = 1; i < a; i++) {
    b = b + abs(A[i].second - A[i + 1].second);
  }
  cout << b;
}
