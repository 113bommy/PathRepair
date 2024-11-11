#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010];
vector<pair<int, int> > v;
vector<pair<int, int> > aux;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int i, j;
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
    a[i]--;
    b[i]--;
    v.push_back(make_pair(a[i], b[i]));
  }
  sort(v.begin(), v.end());
  int pode = 0;
  int k;
  for (k = 1; k < n; k++) {
    if (n % k == 0) {
      j = 0;
      if (j < v.size()) {
        aux.resize(0);
        for (i = j; i < v.size(); i++) {
          aux.push_back(make_pair((v[i].first + k) % n, (v[i].second + k) % n));
        }
        for (i = 0; i < j; i++) {
          aux.push_back(make_pair((v[i].first + k) % n, (v[i].second + k) % n));
        }
        for (i = 0; i < aux.size(); i++) {
          if (aux[i].first > aux[i].second) {
            swap(aux[i].first, aux[i].second);
          }
        }
        sort(aux.begin(), aux.end());
        if (v == aux) {
          pode = 1;
        }
      }
    }
  }
  if (pode == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
