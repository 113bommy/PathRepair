#include <bits/stdc++.h>
using namespace std;
int h, m, n;
int sz;
int cnt = 0;
int keyToInd[200000], keyToPos[200000];
set<int> cache[200000];
map<int, int> valToInd;
int used, iUsed[200000], posUsed[200000];
void add_val(int key, int val) {
  int i = keyToInd[key];
  int pos = keyToPos[key];
  set<int>::iterator it = cache[i].lower_bound(pos);
  if (it == cache[i].end()) {
    it = cache[i].begin();
    cnt += sz;
  }
  iUsed[used] = i;
  posUsed[used] = *it;
  valToInd[val] = used++;
  cnt += *it - pos;
  cache[i].erase(it);
}
void del_val(int val) {
  int i = valToInd[val];
  cache[iUsed[i]].insert(posUsed[i]);
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> h >> m >> n;
  int g = gcd(h, m);
  for (int i = 0; i < g; i++) {
    int cur = i;
    for (int j = 0;; j++) {
      keyToInd[cur] = i;
      keyToPos[cur] = j;
      cache[i].insert(j);
      cur = (cur + m) % h;
      if (cur == i) break;
    }
    sz = cache[i].size();
  }
  for (int i = 0; i < n; i++) {
    char op;
    int id, hash;
    cin >> op >> id;
    if (op == '+') {
      cin >> hash;
      add_val(hash, id);
    } else {
      del_val(id);
    }
  }
  cout << cnt << endl;
}
