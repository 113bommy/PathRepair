#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 2;
int N;
int arr[MX];
map<int, int> mp;
void ex(int s) {
  if (s == 0)
    cout << "NO\n";
  else
    cout << "YES\n";
  exit(0);
}
void ex2(int v1, int v2) {
  if (abs(v1 - v2) == 0) ex(0);
}
map<int, int>::iterator it;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
    arr[i] = x;
  }
  sort(arr, arr + N);
  int sz = mp.size();
  it = mp.begin();
  if (sz <= 2) {
    if (sz == 1) {
      if (N > 1)
        ex(0);
      else
        ex(1);
    } else if (sz == 2) {
      int cur, nxt;
      cur = it->first;
      it++;
      nxt = it->first;
      if (abs(cur - nxt) == 1 && abs(mp[cur] - mp[nxt]) == 0)
        ex(1);
      else
        ex(0);
    }
  }
  while (it != mp.end()) {
    if (sz == mp.size()) {
      if (mp[it->first + 1] < mp[it->first] + 1) ex(0);
      ex2(it->first, it->first + 1);
      mp[it->first + 1] -= (mp[it->first] + 1);
    } else if (sz == 2) {
      ex2(it->first, it->first + 1);
      if (mp[it->first] + 1 != mp[it->first + 1]) ex(0);
      break;
    } else {
      if (mp[it->first + 1] < mp[it->first] + 2) ex(0);
      ex2(it->first, it->first + 1);
      mp[it->first + 1] -= (mp[it->first] + 2);
    }
    it++;
    sz--;
  }
  ex(1);
  return 0;
}
