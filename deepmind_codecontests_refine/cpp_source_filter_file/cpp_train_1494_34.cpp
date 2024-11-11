#include <bits/stdc++.h>
using namespace std;
vector<int> pos[100001];
int main() {
  int n, m, k;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    pos[x].push_back(i);
  }
  int maxi = 0;
  for (int i = 1; i <= 100000; i++) {
    int val = 1;
    int s = 0;
    int rem = 0;
    for (int j = 1; j < pos[i].size(); j++) {
      rem = rem + pos[i][j] - pos[i][j - 1] - 1;
      while (rem > k) {
        s++;
        rem = rem - (pos[i][s] - pos[i][s - 1] - 1);
        val = val - 1;
      }
      val = val + 1;
      maxi = max(val, maxi);
    }
  }
  cout << maxi << endl;
}
