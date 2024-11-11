#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int num, i, sortt, k;
  cin >> num >> k;
  i = 0;
  long long int a[num], b[num];
  map<long long int, long long int> m;
  while (i < num) {
    cin >> a[i];
    m[a[i]]++;
    i++;
  }
  i = 1;
  b[0] = m.size();
  while (i < num) {
    b[i] = b[i - 1];
    if (m[a[i]] == 1) b[i]--;
    m[a[i]]--;
    i += 1;
  }
  while (k--) {
    cin >> sortt;
    cout << b[sortt - 1] << "\n";
  }
  return 0;
}
