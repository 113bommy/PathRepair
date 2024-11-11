#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
string to_str(T str) {
  stringstream stream;
  stream << str;
  return stream.str();
}
template <typename T>
int to_int(T num) {
  int val;
  stringstream stream;
  stream << num;
  stream >> val;
  return val;
}
vector<string> split(const string& s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) elems.push_back(item);
  return elems;
}
const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[5010][5010];
pair<int, int> row[5010], col[5010];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int tt, x, v;
    scanf("%d %d %d", &tt, &x, &v);
    x--;
    if (tt == 1)
      row[x] = make_pair(v, i);
    else
      col[x] = make_pair(v, i);
  }
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      if (row[i].second > col[j].second) {
        printf("%d ", row[i].first);
      } else
        printf("%d ", col[j].first);
    }
    printf("\n");
  }
  return 0;
}
