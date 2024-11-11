#include <bits/stdc++.h>
using namespace std;
char name[100][100];
int score[100];
int main() {
  int n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  int l, r, temp = 0, totalC = 0, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    if (i > 0) {
      int diff = l - temp;
      if (diff > 0) {
        totalC += (diff >= t1 ? t1 : diff) * p1;
        diff -= (diff >= t1 ? t1 : diff);
      }
      if (diff > 0) {
        totalC += (diff >= t2 ? t2 : diff) * p2;
        diff -= (diff >= t2 ? t2 : diff);
      }
      if (diff > 0) {
        totalC += diff * p3;
      }
    }
    totalC += (r - l) * p1;
    temp = r;
  }
  cout << totalC << endl;
}
