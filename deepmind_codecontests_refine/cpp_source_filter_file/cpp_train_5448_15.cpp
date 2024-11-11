#include <bits/stdc++.h>
using namespace std;
int a[1000050];
int b[1000050];
int pos[1000050];
int main() {
  int mx = 0;
  int la, lb;
  cin >> la >> lb;
  for (int i = 0; i < la; i++) scanf("%d", a + i);
  memset(pos, -1, sizeof(pos));
  for (int i = 0; i < lb; i++) {
    scanf("%d", b + i);
    pos[b[i]] = i;
  }
  int first = 0;
  int kol = 0;
  vector<int> podstr(2 * la);
  int curl = 0;
  for (int i = 0; i < 2 * la - 1; i++) {
    int ps = pos[a[i % la]];
    if (ps == -1)
      kol = 0;
    else {
      if (kol == 0) {
        podstr[first] = ps;
        kol++;
        curl == 1;
        if (kol > mx) mx = kol;
      } else {
        int tmp = ps;
        if (podstr[first + kol - 1] > ps) ps += lb;
        curl += ps - podstr[first + kol - 1];
        podstr[first + kol] = tmp;
        kol++;
        while (curl > lb) {
          if (podstr[first] < podstr[first + 1])
            curl -= podstr[first + 1] - podstr[first];
          else
            curl -= lb + podstr[first + 1] - podstr[first];
          first++;
          kol--;
        }
        if (kol > mx) mx = kol;
        if (kol == la) break;
      }
    }
  }
  cout << mx << endl;
  return 0;
}
