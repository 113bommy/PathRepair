#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
map<int, int> mp;
int last = -1;
queue<int> q;
int play() {
  while (q.size()) {
    int z = q.front();
    if (z == last + 1) {
      q.pop();
      last++;
      continue;
    }
    break;
  }
  if (q.size() == 0) {
    return 0;
  }
  int z = q.front();
  q.pop();
  int k = (z - last - 1) % 2;
  last++;
  if (k == 0) return play();
  return !play();
}
int main() {
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    if (mp[a[i]] > 1) {
      cnt++;
    }
  }
  if (cnt > 1) {
    cout << "cslnb" << endl;
    return 0;
  }
  sort(a, a + n);
  int inv = 0;
  if (cnt == 1) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        if (a[i] == 0 || mp[a[i] - 1] > 0) {
          cout << "cslnb" << endl;
          return 0;
        }
        a[i]--;
        break;
      }
    }
    inv = 1;
  }
  for (int i = 0; i < n; i++) {
    q.push(a[i]);
  }
  int ans = play();
  if (inv) ans = !ans;
  if (!ans) {
    cout << "cslnb" << endl;
  } else {
    cout << "sjfnb" << endl;
  }
  return 0;
}
