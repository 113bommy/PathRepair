#include <bits/stdc++.h>
using namespace std;
struct racer {
  string name;
  int points;
};
bool cmp(racer x, racer y) {
  return x.points < y.points || (x.points == y.points && x.name > y.name);
}
bool big(racer x, racer y) {
  return x.points > y.points || (x.points == y.points && x.name < y.name);
}
vector<racer> a;
vector<int> b;
int n, m;
string vasya;
int highest() {
  vector<racer> c(a);
  c[0].points += b[n - 1];
  int p = 0, q = n - 2, h = 1;
  for (int i = n - 1; i > 0; i--) {
    c[i].points += b[q];
    if (big(c[0], c[i]))
      p++;
    else
      h++, q--;
  }
  return h;
}
int lowest() {
  vector<racer> c(a);
  c[0].points += b[n - 1];
  int p = 0, q = n - 1, l = 1;
  for (int i = 1; i < n; i++) {
    c[i].points += b[q];
    if (big(c[0], c[i]))
      p++;
    else
      l++, q--;
  }
  return l;
}
int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].name >> a[i].points;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  cin >> vasya;
  int p = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].name == vasya) {
      p = i;
      break;
    }
  }
  swap(a[p], a[0]);
  sort(a.begin() + 1, a.end(), cmp);
  sort(b.begin(), b.end());
  cout << highest() << " " << lowest();
  return 0;
}
