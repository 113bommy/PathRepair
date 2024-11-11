#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
pair<int, int> a[maxn];
int cn[10], mrk[maxn];
vector<int> vec;
vector<char> c;
int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    cn[a[i].first]++;
    cn[a[i].second]++;
  }
  int last = a[0].first;
  for (int i = 0; i < n; i++)
    if (cn[a[i].first] % 2)
      last = a[i].first;
    else if (cn[a[i].second] % 2)
      last = a[i].second;
  while (cnt < n) {
    int pt = -1;
    for (int i = 0; i < n; i++) {
      if (!mrk[i] and a[i].first == a[i].second and a[i].first == last) {
        vec.push_back(i + 1);
        c.push_back('+');
        cnt++;
        pt = i;
        mrk[i] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      if (pt == -1 and !mrk[i] and a[i].first == last and
          cn[a[i].second] % 2 == 0) {
        pt = i;
        vec.push_back(i + 1);
        c.push_back('+');
        cnt++;
        mrk[i] = true;
        last = a[i].second;
      } else if (pt == -1 and !mrk[i] and a[i].second == last and
                 cn[a[i].first] % 2 == 0) {
        pt = i;
        vec.push_back(i + 1);
        c.push_back('-');
        cnt++;
        mrk[i] = true;
        last = a[i].first;
      }
    }
    for (int i = 0; i < n; i++) {
      if (pt == -1 and !mrk[i] and a[i].first == last) {
        pt = i;
        vec.push_back(i + 1);
        c.push_back('+');
        cnt++;
        mrk[i] = true;
        last = a[i].second;
      } else if (pt == -1 and !mrk[i] and a[i].second == last) {
        pt = i;
        vec.push_back(i + 1);
        c.push_back('-');
        cnt++;
        mrk[i] = true;
        last = a[i].first;
      }
    }
    if (pt == -1) {
      cout << "No solution" << endl;
      return false;
    }
  }
  for (int i = 0; i < n; i++) cout << vec[i] << ' ' << c[i] << endl;
  return false;
}
