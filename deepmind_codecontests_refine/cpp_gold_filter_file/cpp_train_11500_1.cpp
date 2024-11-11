#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
double x[15][15];
double length[N];
double sqr(double X) { return X * X; }
bool check() {
  int len = 0;
  for (int i = 1; i <= 8; ++i) {
    for (int j = i + 1; j <= 8; ++j) {
      if (i != j)
        length[++len] = sqr(x[i][0] - x[j][0]) + sqr(x[i][1] - x[j][1]) +
                        sqr(x[i][2] - x[j][2]);
    }
  }
  sort(length + 1, length + len + 1);
  if (length[1] != length[12]) return false;
  if (length[13] == length[12]) return false;
  if (length[13] != length[24]) return false;
  if (length[25] == length[24]) return false;
  if (length[25] != length[28]) return false;
  cout << "YES\n";
  for (int i = 1; i <= 8; ++i) {
    for (int j = 0; j <= 2; ++j) {
      cout << (int)x[i][j] << " ";
    }
    cout << endl;
  }
  exit(0);
}
void rec(int place) {
  if (place == 9) {
    check();
    return;
  }
  do {
    rec(place + 1);
  } while (next_permutation(x[place], x[place] + 3));
}
int main() {
  for (int i = 1; i <= 8; ++i) {
    cin >> x[i][0] >> x[i][1] >> x[i][2];
    sort(x[i], x[i] + 3);
  }
  rec(2);
  cout << "NO";
  return 0;
}
