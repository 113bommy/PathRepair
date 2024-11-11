#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ct = 0;
    vector<char> A;
    vector<char> B;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        ct++;
        A.push_back(a[i]);
        B.push_back(b[i]);
      }
    }
    if (ct != 2) {
      cout << "NO" << endl;
      continue;
    }
    if (A[1] == A[0] && B[1] == B[1]) {
      cout << "Yes" << endl;
      continue;
    } else {
      cout << "No" << endl;
      continue;
    }
  }
  return 0;
}
