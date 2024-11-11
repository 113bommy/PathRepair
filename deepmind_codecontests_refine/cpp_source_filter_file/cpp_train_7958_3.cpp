#include <bits/stdc++.h>
using namespace std;
pair<int, pair<string, pair<int, int> > > x[11];
int go(vector<int> &v) {
  if ((int)v.size() == 1) {
    if (v[0] == 24) return 1;
    return 0;
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      vector<int> aux = v;
      aux.erase(aux.begin() + j);
      aux.erase(aux.begin() + i);
      aux.push_back(v[i] + v[j]);
      x[aux.size()] =
          make_pair(v[i], make_pair("+", make_pair(v[j], v[i] + v[j])));
      if (go(aux)) return 1;
      aux.pop_back();
      aux.push_back(v[i] - v[j]);
      x[aux.size()] =
          make_pair(v[i], make_pair("-", make_pair(v[j], v[i] - v[j])));
      if (go(aux)) return 1;
      aux.pop_back();
      aux.push_back(v[j] - v[i]);
      x[aux.size()] =
          make_pair(v[j], make_pair("-", make_pair(v[i], v[j] - v[i])));
      if (go(aux)) return 1;
      aux.pop_back();
      aux.push_back(v[j] * v[i]);
      x[aux.size()] =
          make_pair(v[j], make_pair("*", make_pair(v[i], v[j] * v[i])));
      if (go(aux)) return 1;
    }
  }
  return 0;
}
int main() {
  int i, n;
  vector<int> v;
  scanf("%d", &n);
  if (n < 7) {
    for (int j = 1; j <= n; j++) v.push_back(j);
    int y = go(v);
    if (y) {
      printf("YES\n");
      for (int j = n - 1; j >= 1; j--)
        cout << x[j].first << " " << x[j].second.first << " "
             << x[j].second.second.first << " = " << x[j].second.second.second
             << endl;
    } else
      printf("NO\n");
  } else {
    int y = 24, f = 0;
    int aux = n % 4;
    if (aux == 3) i = 8;
    if (!aux) i = 9;
    if (aux == 1) i = 10;
    if (aux == 2) i = 11;
    for (int j = 1; j < i; j++) v.push_back(j);
    printf("YES\n");
    go(v);
    for (int j = i - 2; j >= 1; j--)
      cout << x[j].first << " " << x[j].second.first << " "
           << x[j].second.second.first << " = " << x[j].second.second.second
           << endl;
    for (; i <= n; i += 2, f = 1 - f) {
      if (f) {
        printf("%d + %d = %d\n", y, i, y + i);
        y += i;
        printf("%d - %d = %d\n", y, i + 1, y - (i + 1));
        y -= (i + 1);
      } else {
        printf("%d - %d = %d\n", y, i, y - i);
        y -= i;
        printf("%d - %d = %d\n", y, i + 1, y + i + 1);
        y += i + 1;
      }
    }
  }
  return 0;
}
