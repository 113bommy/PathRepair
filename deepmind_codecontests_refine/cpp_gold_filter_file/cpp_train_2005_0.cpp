#include <bits/stdc++.h>
using namespace std;
void rev(string *a, int l) {
  string atmp = (*a).substr(0, l);
  for (int i = 0; i < l; i++) {
    (*a)[i] = atmp[l - i - 1];
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    vector<int> res;
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == b[i]) continue;
      int l = i + 1;
      if (a[0] == b[i]) {
        c += 2;
        res.push_back(1);
        res.push_back(i + 1);
        a[0] = a[0] == '0' ? '1' : '0';
        for (int j = 0; j < l; j++) {
          a[j] = a[j] == '0' ? '1' : '0';
        }
      } else {
        c++;
        res.push_back(i + 1);
        for (int j = 0; j < l; j++) {
          a[j] = a[j] == '0' ? '1' : '0';
        }
      }
      rev(&a, l);
    }
    cout << c;
    if (c > 0) {
      for (int i = 0; i < res.size(); i++) {
        cout << " " << res[i];
      }
    }
    cout << "\n";
  }
  return 0;
}
