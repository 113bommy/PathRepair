#include <bits/stdc++.h>
using namespace std;
int n, rr[10009], v[10009], give[10009];
char arr[1009][1009];
vector<int> Party;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++) scanf("%d", &rr[i]);
  while (true) {
    int go = -21012000;
    for (int i = 0; i < n; i++)
      if (v[i] == 0 and give[i] == rr[i]) go = i;
    if (go == -21012000) break;
    Party.push_back(go + 1);
    for (int i = 0; i < n; i++)
      if (arr[go][i] != '0') give[i]++;
  }
  printf("%d\n", Party.size());
  for (int i = 0; i < Party.size(); i++) printf("%d ", Party[i]);
  printf("\n");
  exit(0);
}
