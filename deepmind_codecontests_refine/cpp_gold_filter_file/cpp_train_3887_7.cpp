#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n;
  cin >> n;
  const int N = n;
  unsigned int m[N], sum = 0;
  for (int i(0); i < n; i++) {
    cin >> m[i];
    sum += m[i];
  }
  sort(m, m + n);
  unsigned int myMonets = 0, count = 0;
  for (int i(n - 1); i >= 0; i--) {
    myMonets += m[i];
    count++;
    if (myMonets > (sum - myMonets)) break;
  }
  cout << count;
  return 0;
}
