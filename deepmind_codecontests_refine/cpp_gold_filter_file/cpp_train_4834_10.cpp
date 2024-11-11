#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int ech[109], muoi[109];
vector<pair<int, int> > a;
void read() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) scanf("%d", &ech[i]);
  for (int i = 0; i < k; i++) scanf("%d", &muoi[i]);
}
void process() {
  int i, j;
  for (i = 0; i < m; i++) {
    int t = 0;
    for (j = 0; j < k; j++)
      if (muoi[j] % ech[i] == 0) t++;
    pair<int, int> tmp = make_pair(t, i + 1);
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  int h = (int)a.size();
  i = 0;
  int tong = 0;
  while (i < h && a[i].first == a[0].first) {
    tong++;
    i++;
  }
  cout << tong << endl;
  i = 0;
  while (i < h && a[i].first == a[0].first) {
    cout << a[i].second << " ";
    i++;
  }
}
int main() {
  read();
  process();
  if (0) {
    cout << m << " " << n << " " << k << endl;
    for (int i = 0; i < m; i++) cout << ech[i] << " ";
    cout << endl;
    for (int j = 0; j < k; j++) cout << muoi[j] << " ";
    cout << endl;
    cin.get();
  }
  return 0;
}
