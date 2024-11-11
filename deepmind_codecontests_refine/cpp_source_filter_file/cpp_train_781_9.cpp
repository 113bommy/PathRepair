#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<long long> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<int> online(k);
  vector<int> online_v(k);
  int value = 0;
  int type, id;
  int minvalue;
  int minplace;
  for (int i = 0; i < q; i++) {
    cin >> type >> id;
    id--;
    if (type == 1) {
      value = t[id];
      minvalue = online_v[0];
      minplace = 0;
      for (int j = 0; j < k; j++) {
        if (online_v[j] < minvalue) {
          minvalue = online_v[j];
          minplace = j;
        }
      }
      if (minvalue < value) {
        online[minplace] = id;
        online_v[minplace] = value;
      }
    } else {
      int found = 0;
      for (int j = 0; j < k; j++) {
        if (online[j] == id) {
          cout << "YES\n";
          found = 1;
        }
      }
      if (found == 0) cout << "NO\n";
    }
  }
}
