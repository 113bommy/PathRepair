#include <bits/stdc++.h>
using namespace std;
void pre_op(string &a, int i) {
  for (int j = 0; j <= i; j++) {
    if (a[j] == '0')
      a[j] = '1';
    else
      a[j] = '0';
  }
  for (int j = 0; j <= i / 2; j++) {
    char c = a[i - j];
    a[i - j] = a[i];
    a[j] = c;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> k;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == b[i])
        continue;
      else if (a[0] == b[i]) {
        k.push_back(1);
        pre_op(a, 0);
      }
      k.push_back(i + 1);
      pre_op(a, i);
    }
    cout << k.size() << " ";
    for (int i : k) cout << i << " ";
    cout << endl;
  }
  return 0;
}
