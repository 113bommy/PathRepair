#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int vis[maxn];
int main() {
  string s1, s2;
  int n;
  cin >> n;
  cin >> s1 >> s2;
  vector<int> V;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      int pos = 0;
      for (int j = i + 1; j < n; j++) {
        if (s2[i] == s1[j]) {
          pos = j;
          break;
        }
      }
      if (pos == 0) {
        puts("-1");
        return 0;
      }
      for (int j = pos; j >= i + 1; j--) {
        swap(s1[j], s1[j - 1]);
        V.push_back(j - 1);
      }
    }
  }
  cout << V.size() << endl;
  for (int i = 0; i < V.size(); i++) cout << V[i] + 1 << " ";
}
