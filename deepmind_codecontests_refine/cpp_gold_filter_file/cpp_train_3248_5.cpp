#include <bits/stdc++.h>
using namespace std;
const int NEW = 0, IN_COMPANY = 1, LEAVE = 2;
int state[1000001];
int a[100001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int cnt = 0, counter = 0;
  set<int> here;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    counter++;
    int x = abs(a[i]);
    if (a[i] > 0) {
      if (state[x] == NEW) {
        cnt++;
        here.insert(x);
        state[x] = IN_COMPANY;
      } else {
        return cout << -1, 0;
      }
    } else {
      if (state[x] == IN_COMPANY) {
        cnt--;
        state[x] = LEAVE;
      } else {
        return cout << -1, 0;
      }
    }
    if (!cnt) {
      v.push_back(counter);
      counter = 0;
      for (auto &i : here) {
        state[i] = NEW;
      }
      here.clear();
    }
  }
  if (cnt) return cout << -1, 0;
  cout << v.size() << "\n";
  for (int &i : v) {
    cout << i << " ";
  }
  return 0;
}
