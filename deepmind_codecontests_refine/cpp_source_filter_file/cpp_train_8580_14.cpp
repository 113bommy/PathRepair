#include <bits/stdc++.h>
using namespace std;
int main() {
  int kbeer = (int)1e9;
  int n, k, scnt = 0;
  cin >> n >> k;
  vector<int> list(n);
  vector<pair<int, int> > my(n);
  vector<pair<int, int> > h7otfeeh;
  for (int i = 0; i < n; i++) cin >> list[i];
  for (int i = 1; i < 1000; i++) {
    int l = i;
    int count = 0;
    my.clear();
    vector<pair<int, int> > my(n);
    for (int j = 0; j < n; j++) {
      if (l != list[j]) {
        count++;
        my[j].first = j + 1;
        my[j].second = list[j] - l;
      }
      l += k;
    }
    if (kbeer > count) {
      h7otfeeh = my;
      scnt = count;
      kbeer = count;
    }
  }
  cout << scnt << endl;
  for (int i = 0; i < n; i++) {
    if (h7otfeeh[i].second != 0) {
      if (h7otfeeh[i].second > 0)
        cout << "+";
      else
        cout << "-";
      cout << " " << h7otfeeh[i].first << " ";
      cout << abs(h7otfeeh[i].second) << endl;
    }
  }
}
