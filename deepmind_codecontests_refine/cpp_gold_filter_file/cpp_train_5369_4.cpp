#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int a[8][8];
vector<pair<int, int> > v;
void add(int x, int t) {
  if (t == 1) {
    for (int j = 0; j <= 6; j++) a[x][j] = a[x][j + 1];
    a[x][6] = a[x][0];
  }
  if (t == 2) {
    for (int j = 7; j >= 1; j--) a[x][j] = a[x][j - 1];
    a[x][1] = a[x][7];
  }
  if (t == 3) {
    for (int i = 0; i <= 6; i++) a[i][x] = a[i + 1][x];
    a[6][x] = a[0][x];
  }
  if (t == 4) {
    for (int i = 7; i >= 1; i--) a[i][x] = a[i - 1][x];
    a[1][x] = a[7][x];
  }
  v.push_back(make_pair(t, x));
}
void swap1(int i, int j) {
  add(j + 1, 4);
  add(i, 2);
  add(j + 1, 4);
  add(i, 1);
  add(j + 1, 4);
  add(i, 2);
  add(j + 1, 4);
  add(i, 1);
  add(j + 1, 4);
  add(i, 2);
  add(j + 1, 4);
  add(i, 1);
  add(j + 1, 4);
}
void swap2(int i, int j) {
  add(i + 1, 2);
  add(j, 4);
  add(i + 1, 2);
  add(j, 3);
  add(i + 1, 2);
  add(j, 4);
  add(i + 1, 2);
  add(j, 3);
  add(i + 1, 2);
  add(j, 4);
  add(i + 1, 2);
  add(j, 3);
  add(i + 1, 2);
}
void writee() {
  cout << endl;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= 6; j++) {
      char c;
      cin >> c;
      if (c >= '0' && c <= '9')
        a[i][j] = c - '0' + 1;
      else
        a[i][j] = c - 'A' + 11;
    }
  int x = 0;
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= 6; j++) {
      x++;
      int l, r;
      for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
          if (a[i][j] == x) {
            l = i;
            r = j;
          }
      while (r > j) {
        swap1(l, r - 1);
        r--;
      }
      while (r < j) {
        swap1(l, r);
        r++;
      }
      while (l > i) {
        swap2(l - 1, r);
        l--;
      }
    }
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == 1) cout << "L";
    if (v[i].first == 2) cout << "R";
    if (v[i].first == 3) cout << "U";
    if (v[i].first == 4) cout << "D";
    cout << v[i].second << "\n";
  }
}
