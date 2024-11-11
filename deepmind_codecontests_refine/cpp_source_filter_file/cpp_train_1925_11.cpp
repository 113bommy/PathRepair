#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int> > resp;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      int j = 0;
      while (a[i] != b[j]) {
        j++;
      }
      while (j > i) {
        resp.push_back(pair<int, int>(j, j + 1));
        swap(b[j], b[j - 1]);
        j--;
      }
    }
  }
  cout << resp.size() << endl;
  for (auto x : resp) {
    cout << x.first << " " << x.second << endl;
  }
}
