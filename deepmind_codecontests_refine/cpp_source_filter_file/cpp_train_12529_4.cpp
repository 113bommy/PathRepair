#include <bits/stdc++.h>
using namespace std;
int findval[101];
void init(int n) {
  for (int i = 0; i < n; i++) findval[i] = i;
}
int findpos(int pos) {
  if (findval[pos] == pos)
    return pos;
  else
    return findpos(findval[pos]);
}
int main() {
  int n;
  cin >> n;
  init(n);
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (x[i] == x[j] || y[i] == y[j]) {
        int v1, v2;
        v1 = findpos(i);
        v2 = findpos(j);
        findval[v1] = v2;
      }
    }
  }
  map<int, int> mm;
  for (int i = 0; i < n; i++) {
    mm[findval[i]]++;
  }
  cout << mm.size() - 1 << endl;
  return 0;
}
