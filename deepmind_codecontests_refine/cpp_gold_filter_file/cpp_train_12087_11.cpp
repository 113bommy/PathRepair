#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;
int main() {
  cin >> n;
  vector<int> vc;
  for (int i = 0; i < n; i++) {
    cin >> k;
    vc.push_back(k);
  }
  for (int i = 0; i < vc.size(); i++) {
    cnt += vc[i];
  }
  if (cnt == 0)
    printf("Easy");
  else
    printf("HARD");
  return 0;
}
