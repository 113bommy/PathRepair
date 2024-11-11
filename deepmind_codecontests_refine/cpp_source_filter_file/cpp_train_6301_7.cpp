#include <bits/stdc++.h>
using namespace std;
int main() {
  long k, m;
  string s;
  vector<int> rooms;
  cin >> k >> m;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      rooms.push_back(i);
    }
  }
  long select, fin = k;
  long p = 0, l = 0, r = m, i = 0;
  while (r < rooms.size()) {
    select = k;
    while ((max(rooms[p] - rooms[l], rooms[r] - rooms[p]) < select)) {
      select = max(rooms[p] - rooms[l], rooms[r] - rooms[p]);
      p++;
      if (p >= rooms.size()) break;
    }
    if (select < fin) fin = select;
    l++;
    r++;
  }
  cout << fin;
}
