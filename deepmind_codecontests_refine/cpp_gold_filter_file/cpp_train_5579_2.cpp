#include <bits/stdc++.h>
using namespace std;
using namespace std;
bool cnt[12345];
bool cntneg[12345];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool shit = false;
  for (int i = 0; i < (m); i++) {
    int k;
    scanf("%d", &k);
    bool chill = false;
    int tmp;
    for (int j = 0; j < (n + 1); j++) cnt[j] = 0;
    for (int j = 0; j < (n + 1); j++) cntneg[j] = 0;
    for (int z = 0; z < (k); z++) {
      scanf("%d", &tmp);
      if (tmp > 0)
        cnt[tmp] = true;
      else
        cntneg[-tmp] = true;
      if (cnt[abs(tmp)] && cntneg[abs(tmp)]) chill = true;
    }
    if (!chill) shit = true;
  }
  if (shit)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
