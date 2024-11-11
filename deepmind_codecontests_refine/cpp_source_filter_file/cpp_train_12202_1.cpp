#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXV = 10, MAXE = 10;
int num[MAXN];
int pos[MAXN];
bool ok[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int kase;
  cin >> kase;
  while (kase--) {
    int nlen;
    cin >> nlen;
    memset(ok, 0, sizeof(ok));
    for (int i = 1; i <= nlen; i++) {
      cin >> num[i];
      pos[num[i]] = i;
    }
    int l = pos[1], r = pos[1];
    vector<int> vec;
    vec.push_back(1);
    ok[1] = 1;
    int maxx = 1;
    for (int i = 2; i <= nlen; i++) {
      int nex = pos[i];
      if (nex < l) {
        while (l != nex) {
          l--;
          vec.push_back(num[l]);
          maxx = max(maxx, num[l]);
        }
      } else if (r < nex) {
        while (r != nex) {
          r++;
          vec.push_back(num[r]);
          maxx = max(maxx, num[r]);
        }
      }
      if (maxx = r - l + 1) {
        ok[maxx] = 1;
      }
    }
    for (int i = 1; i <= nlen; i++) cout << !!ok[i];
    cout << endl;
  }
  return 0;
}
