#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, count;
  cin >> n >> m;
  count = m;
  for (int i = 1; i < n; i++) {
    cin >> m;
    cout << m + count << " ";
    count = m;
  }
  cout << endl;
  return 0;
}
