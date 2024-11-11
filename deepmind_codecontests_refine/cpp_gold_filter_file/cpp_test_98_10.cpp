#include <bits/stdc++.h>
using namespace std;
using li = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, w;
    cin >> s >> w;
    int l;
    l = w.size();
    int a[l];
    int dif = 0;
    for (int i = 0; i < w.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        if (w[i] == s[j]) {
          a[i] = j + 1;
        }
      }
    }
    for (int i = 0; i < l - 1; i++) {
      dif += abs(a[i] - a[i + 1]);
    }
    cout << dif << endl;
  }
}
