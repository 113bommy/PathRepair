#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int sn = n;
  int fir = 0;
  vector<int> ans;
  while (n > 0) {
    if (fir == 0) {
      ans.push_back(6);
      fir = 1;
      n -= 4;
    } else if (fir == 1) {
      ans.push_back(5);
      n -= 4;
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    printf("%d", ans[i]);
  }
  printf("\n");
  fir = 0;
  int j = 0;
  vector<int> ans2;
  while (j < ans.size()) {
    ans2.push_back(4);
    j++;
  }
  for (int i = ans2.size() - 1; i >= 0; i--) {
    printf("%d", ans2[i]);
  }
  printf("\n");
}
