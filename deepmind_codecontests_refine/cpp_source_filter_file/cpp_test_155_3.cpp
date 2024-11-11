#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    map<int, int> a, b;
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        a.insert({p[i], i});
      }
      if (s[i] == '0') {
        b.insert({p[i], i});
      }
    }
    int i = 1;
    auto ita = a.begin();
    while (ita != a.end()) {
      q[ita->second] = i;
      i++;
      ita++;
    }
    auto itb = b.begin();
    while (itb != b.end()) {
      q[itb->second] = i;
      i++;
      itb++;
    }
    for (int j = 0; j < q.size(); ++j) {
      cout << q[j] << " ";
    }
    cout << endl;
  }
}
