#include <bits/stdc++.h>
using namespace std;
int n, k;
char line[100010];
vector<int> cua;
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &k);
  scanf("%c", &line[0]);
  for (int i = 1; i <= n; i++) {
    scanf("%c", &line[i]);
    if (line[i] == '7' && line[i - 1] == '4') {
      cua.push_back(i - 1);
    }
  }
  int p;
  int cont = 0;
  while (!cua.empty() && cont < k) {
    cont += 1;
    p = cua[0];
    if (p % 2) {
      line[p + 1] = '4';
      if (p + 2 <= n && line[p + 2] == '7') {
        cua[0] = p + 1;
      } else {
        cua.erase(cua.begin());
      }
    } else {
      line[p] = '7';
      if ((p - 1) >= 1 && line[p - 1] == '4') {
        cua[0] = p - 1;
        if ((k - cont - 1) % 2 == 1) {
          line[p] = '4';
        }
        break;
      } else {
        cua.erase(cua.begin());
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%c", line[i]);
  }
  return 0;
}
