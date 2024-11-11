#include <bits/stdc++.h>
int S[200][200005];
using namespace std;
int main() {
  int n;
  int vis1[200] = {0};
  int m;
  string s;
  string f;
  int sum;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    vis1[s[i]]++;
    S[s[i]][vis1[s[i]]] = i + 1;
  }
  cin >> m;
  while (m--) {
    cin >> f;
    sum = 0;
    int vis2[200] = {0};
    for (int i = 0; i < f.size(); i++) {
      vis2[f[i]]++;
      sum = max(sum, S[f[i]][vis2[f[i]]]);
    }
    printf("%d\n", sum);
  }
  return 0;
}
