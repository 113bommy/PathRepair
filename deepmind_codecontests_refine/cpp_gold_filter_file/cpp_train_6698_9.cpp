#include <bits/stdc++.h>
using namespace std;
int third[100005], fourth[100005];
int main() {
  int n, nn;
  cin >> n;
  for (auto i = 0; i < n; i++) cin >> third[i];
  for (auto i = 0; i < n; i++) {
    cin >> nn;
    fourth[third[i]] = nn;
  }
  for (auto i = 1; i <= n; i++) cout << fourth[i] << " ";
  return 0;
}
