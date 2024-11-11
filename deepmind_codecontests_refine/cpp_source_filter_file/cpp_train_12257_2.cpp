#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int count = 0;
  long long int a[n];
  long long int b[n];
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) {
    cin >> b[i];
    m[i + 1] = i;
    a[i] = i + 1;
  }
  for (long long int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      long long int x = m[b[i]];
      swap(m[a[i]], m[b[i]]);
      swap(a[i], a[x]);
      count++;
    }
  }
  if (count % 2 == n % 2) {
    cout << "Petr" << endl;
  } else {
    cout << "um_nik" << endl;
  }
  return 0;
}
