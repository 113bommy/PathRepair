#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 5;
int n, k;
int bsize;
set<int> alive[maxn];
int cnt;
char ask(int i) {
  cnt++;
  cout << "? " << i + 1 << endl;
  cout.flush();
  char res;
  cin >> res;
  if (res == 'E') exit(0);
  return res;
}
void reset() {
  cout << "R" << endl;
  cout.flush();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  bsize = max(1, k / 2);
  for (int i = 0; i < n; i++) {
    alive[i / bsize].insert(i);
  }
  reset();
  set<int> kill;
  for (int i = 0; i < n; i++) {
    if (ask(i) == 'Y') {
      kill.insert(i);
    }
  }
  for (int x : kill) {
    alive[x / bsize].erase(x);
  }
  for (int i = 0; i < n / bsize; i++) {
    for (int j = i; j < n / bsize; j++) {
      if (alive[j].empty()) continue;
      reset();
      for (int x : alive[i]) {
        assert(ask(x) == 'N');
      }
      set<int> kill;
      for (int x : alive[j]) {
        if (ask(x) == 'Y') {
          kill.insert(x);
        }
      }
      for (int x : kill) {
        alive[j].erase(x);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n / bsize; i++) {
    ans += alive[i].size();
  }
  cout << "! " << ans << endl;
  cout.flush();
  return 0;
}
