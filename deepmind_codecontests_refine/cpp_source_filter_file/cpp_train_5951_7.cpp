#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[0] == a[n])
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
  return 0;
}
