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
    S[s[i]][vis1[s[i]]] = i;
  }
  cin >> m;
  while (m--) {
    cin >> f;
    sum = 0;
    int vis2[200] = {0};
    for (int i = 0; i < f.size(); i++) {
      vis2[s[i]]++;
      sum = max(sum, S[s[i]][vis2[s[i]]]);
    }
    printf("%d\n", sum);
  }
  return 0;
}
