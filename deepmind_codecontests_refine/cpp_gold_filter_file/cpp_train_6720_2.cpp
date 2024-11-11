#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = 0, k = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) m++;
    if (a < b) k++;
  }
  if (m > k) cout << "Mishka";
  if (m < k) cout << "Chris";
  if (m == k) cout << "Friendship is magic!^^";
  return 0;
}
