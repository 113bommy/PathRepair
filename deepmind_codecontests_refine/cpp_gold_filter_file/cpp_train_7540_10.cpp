#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-7;
const int MAX_N = 1000;
const int MAX_RANGE = 3000;
vector<pair<int, char> > lho[MAX_RANGE + 5];
int data[MAX_N + 5];
vector<pair<int, char> > *row = lho + 1500;
int main() {
  int N;
  scanf("%d", &N);
  for (int(i) = 0, (_batas) = (N); (i) < (_batas); (i)++) scanf("%d", &data[i]);
  int minnR = 0, maxxR = 0;
  int currR = 0, currC = 0;
  for (int(i) = 0, (_batas) = (N); (i) < (_batas); (i)++) {
    int dr = (i % 2 ? 1 : -1);
    char c = (i % 2 ? '\\' : '/');
    for (int(j) = 0, (_batas) = (data[i]); (j) < (_batas); (j)++) {
      row[currR + dr * j].push_back(make_pair(currC + j, c));
      ;
    }
    currR += (data[i] - 1) * dr;
    minnR = min(minnR, currR);
    maxxR = max(maxxR, currR);
    currC += data[i];
  }
  int maxxC = 0;
  for (int(i) = (minnR), (_batas) = (maxxR); (i) <= (_batas); (i)++) {
    maxxC = max(maxxC, row[i].back().first);
  }
  for (int(i) = (minnR), (_batas) = (maxxR); (i) <= (_batas); (i)++) {
    int currC = 0;
    for (int(j) = 0, (_batas) = (((int)(row[i]).size())); (j) < (_batas);
         (j)++) {
      for (int(k) = 0, (_batas) = (row[i][j].first - currC); (k) < (_batas);
           (k)++)
        printf(" ");
      printf("%c", row[i][j].second);
      currC = row[i][j].first + 1;
    }
    for (int(j) = 0, (_batas) = (maxxC - currC + 1); (j) < (_batas); (j)++)
      printf(" ");
    puts("");
  }
  return 0;
}
