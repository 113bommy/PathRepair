#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar.begin(), ar.end(), greater<int>());
  int x = 0, y = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    if (i == j) {
      x += ar[i];
      i++;
    } else {
      x += ar[i];
      y += ar[j];
      i++;
      j--;
    }
  }
  long long dist = x * x + y * y;
  cout << dist;
  return 0;
}
