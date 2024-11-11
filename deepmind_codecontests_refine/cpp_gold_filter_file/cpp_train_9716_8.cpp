#include <bits/stdc++.h>
using namespace std;
int suspect[100000];
int justify[100000];
bool killer[100000];
pair<int, int> a[100000];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    killer[i] = false;
    char x;
    int k;
    scanf("%d", &k);
    if (k < 0) {
      x = '-';
      k *= -1;
    } else
      x = '+';
    k--;
    if (x == '+') {
      suspect[k]++;
      a[i].second = 1;
    } else {
      a[i].second = 0;
      justify[k]++;
      cnt++;
    }
    a[i].first = k;
  }
  int cntkiller = 0;
  for (int i = 0; i < n; i++)
    if (suspect[i] + cnt - justify[i] == m) {
      killer[i] = true;
      cntkiller++;
    }
  for (int i = 0; i < n; i++) {
    if (a[i].second == 1 && killer[a[i].first] && cntkiller == 1)
      printf("Truth\n");
    else if (a[i].second == 0 && killer[a[i].first] && cntkiller == 1)
      printf("Lie\n");
    else if (a[i].second == 1 && killer[a[i].first])
      printf("Not defined\n");
    else if (a[i].second == 1 && !killer[a[i].first])
      printf("Lie\n");
    else if (a[i].second == 0 && !killer[a[i].first])
      printf("Truth\n");
    else
      printf("Not defined\n");
  }
}
