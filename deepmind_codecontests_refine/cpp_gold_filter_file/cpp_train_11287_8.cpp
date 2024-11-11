#include <bits/stdc++.h>
using namespace std;
void fun(vector<int>& a) {
  int n = a.size();
  map<int, int> mp;
  for (int i = 1; i < a.size(); i++) mp[a[i] - a[i - 1]]++;
  if (mp.size() == 1) {
    if ((mp.begin()->first) == 0)
      cout << "1" << endl << a[0] << endl;
    else
      cout << "2" << endl
           << a[0] - (mp.begin()->first) << " "
           << a[n - 1] + (mp.begin()->first) << endl;
  } else if (mp.size() >= 3)
    cout << "0" << endl;
  else {
    auto it = mp.begin();
    int d1 = it->first;
    it++;
    int d2 = it->first;
    if (mp[d2] == 1) {
      if ((d2 / 2) == d1 && (d2 % 2 == 0)) {
        for (int i = 1; i < n; i++)
          if ((a[i] - a[i - 1]) == d2) {
            cout << "1" << endl << a[i] - d1;
            return;
          }
      } else
        cout << "0" << endl;
    } else
      cout << "0" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if (n == 1)
    cout << "-1" << endl;
  else if (n == 2) {
    int diff = (a[1] - a[0]);
    if (diff == 0) {
      cout << "1" << endl << a[0] << endl;
    } else if (diff % 2 == 0) {
      cout << "3" << endl
           << a[0] - diff << " " << a[0] + (diff / 2) << " " << a[1] + diff;
    } else
      cout << "2" << endl << a[0] - diff << " " << a[1] + diff;
  } else
    fun(a);
}
