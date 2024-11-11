#include <bits/stdc++.h>
using namespace std;
void readFile();
vector<int> omar;
vector<bool> flag;
int main() {
  readFile();
  int n, d;
  scanf("%d %d", &n, &d);
  omar.resize(n * 2);
  flag.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &omar[i]);
    omar[n + i] = omar[i];
  }
  int offSum = 1e5, ans = 0;
  for (int i = 0; i < n; i++) {
    if (flag[i]) continue;
    int ind = i, cSum = 0;
    for (int j = i; j < n + i; j += d) {
      cSum += omar[j];
      flag[j] = true;
    }
    if (cSum < offSum) offSum = cSum, ans = ind;
  }
  printf("%d\n", ans + 1);
}
void readFile() {}
