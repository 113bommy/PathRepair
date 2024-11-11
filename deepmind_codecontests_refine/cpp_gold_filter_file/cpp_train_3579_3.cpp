#include <bits/stdc++.h>
using namespace std;
int Link[400];
int a[5], n, O, Z;
bool visit[400];
bool win = true;
int main() {
  for (int i = 0; i < 400; ++i) Link[i] = 500;
  memset(visit, false, sizeof(visit));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (n == 3) {
    if ((a[1] ^ (a[2] ^ a[3])) != 0)
      win = true;
    else
      win = false;
  } else if (n == 2) {
    int cur = -1;
    for (int delta = 0; cur + delta < 350; ++delta) {
      ++cur;
      while (visit[cur] && cur + delta < 350) ++cur;
      if (cur + delta >= 350) break;
      Link[cur] = cur + delta;
      Link[cur + delta] = cur;
      visit[cur] = visit[cur + delta] = true;
    }
    if (Link[a[1]] == a[2])
      win = false;
    else
      win = true;
  } else if (n == 1)
    if (a[1] == 0)
      win = false;
    else
      win = true;
  if (win)
    cout << "BitLGM" << endl;
  else
    cout << "BitAryo" << endl;
  return 0;
}
