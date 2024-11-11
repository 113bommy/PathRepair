#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(int x, int y) { return x > y; }
};
int a[100010];
map<int, int> m;
set<int, cmp> s;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    m[a[i]]++;
    if (m[a[i]] == 1)
      s.insert(a[i]);
    else if (m[a[i]] == 2)
      s.erase(a[i]);
  }
  if (s.size() == 0)
    cout << "Noting\n";
  else
    cout << (*s.begin()) << endl;
  for (int l = 0, i = k; i < n; i++, l++) {
    m[a[l]]--;
    if (m[a[l]] == 0) {
      s.erase(a[l]);
    } else if (m[a[l]] == 1) {
      s.insert(a[l]);
    }
    m[a[i]]++;
    if (m[a[i]] == 1) {
      s.insert(a[i]);
    } else if (m[a[i]] == 2) {
      s.erase(a[i]);
    }
    if (s.size() == 0)
      cout << "Nothing\n";
    else
      cout << (*s.begin()) << endl;
  }
}
