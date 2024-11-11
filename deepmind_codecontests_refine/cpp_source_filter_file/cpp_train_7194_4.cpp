#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int max1 = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[j] - v[i] == j - i && (v[i] == 1) || (v[j] == 1000))
        max1 = max(max1, j - i);
      else if ((v[j] - v[i]) == (j - i))
        max1 = max(max1, j - i - 1);
    }
  }
  cout << max1;
}
