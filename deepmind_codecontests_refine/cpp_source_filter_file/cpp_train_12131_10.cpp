#include <bits/stdc++.h>
using namespace std;
char s[100100], t[100100];
vector<int> pos[30];
int main() {
  int n, k;
  scanf("%d%d ", &n, &k);
  long long int res;
  int len;
  scanf("%s ", s);
  len = k;
  for (int i = 0; i < len; i++) pos[s[i] - 'a'].push_back(i);
  for (int i = 0; i < n; i++) {
    int nt;
    scanf("%s ", t);
    nt = strlen(t);
    res = 0;
    for (int j = 0; j < nt; j++) {
      if (pos[t[j] - 'a'].size() == 0)
        res += nt;
      else {
        vector<int>::iterator p =
            upper_bound(pos[t[j] - 'a'].begin(), pos[t[j] - 'a'].end(), j);
        if (p == pos[t[j] - 'a'].begin())
          res += abs((*p) - j);
        else if (p == pos[t[j] - 'a'].end())
          res += abs((*(p - 1)) - j);
        else
          res += min(abs((*p) - j), abs((*(p - 1)) - j));
      }
    }
    cout << res << endl;
  }
  return 0;
}
