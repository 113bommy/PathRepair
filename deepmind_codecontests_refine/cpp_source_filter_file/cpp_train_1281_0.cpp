#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
struct line {
  long long x1, y1, x2, y2;
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  line ln[4];
  for (long long i = 0; i < 4; i++)
    cin >> ln[i].x1 >> ln[i].y1 >> ln[i].x2 >> ln[i].y2;
  long long done = 1;
  vector<long long> xpar, ypar;
  for (long long i = 0; i < 4; i++) {
    if (ln[i].x1 == ln[i].x2 && ln[i].y1 != ln[i].y2)
      ypar.push_back(i);
    else if (ln[i].x1 != ln[i].x2 && ln[i].y1 == ln[i].y2)
      xpar.push_back(i);
    else {
      cout << "NO";
      return 0;
    }
  }
  if (xpar.size() != ypar.size()) {
    cout << "NO";
    return 0;
  }
  long long xlen1 = -1, ylen1 = -1, xlen2 = -1, ylen2 = -1;
  xlen1 = abs(ln[xpar[0]].x1 - ln[xpar[0]].x2);
  xlen2 = abs(ln[xpar[1]].x1 - ln[xpar[1]].x2);
  ylen1 = abs(ln[ypar[0]].y1 - ln[ypar[0]].y2);
  ylen2 = abs(ln[ypar[1]].y1 - ln[ypar[1]].y2);
  if (xlen1 != xlen2 || ylen1 != ylen2 || xlen1 == 0 || ylen1 == 0 ||
      xlen2 == 0 || ylen2 == 0) {
    cout << "NO";
    return 0;
  }
  line temp;
  temp.x1 = -1;
  temp.x2 = -1;
  temp.y1 = -1;
  temp.y2 = -1;
  for (long long i = 0; i < 2; i++) {
    if (ln[xpar[0]].x1 == ln[ypar[i]].x1 && ln[xpar[0]].y1 == ln[ypar[i]].y1) {
      temp.x1 = ln[ypar[i]].x2;
      temp.y1 = ln[ypar[i]].y2;
    } else if (ln[xpar[0]].x1 == ln[ypar[i]].x2 &&
               ln[xpar[0]].y1 == ln[ypar[i]].y2) {
      temp.x1 = ln[ypar[i]].x1;
      temp.y1 = ln[ypar[i]].y1;
    }
  }
  for (long long i = 0; i < 2; i++) {
    if (ln[xpar[0]].x2 == ln[ypar[i]].x1 && ln[xpar[0]].y2 == ln[ypar[i]].y1) {
      temp.x2 = ln[ypar[i]].x2;
      temp.y2 = ln[ypar[i]].y2;
    } else if (ln[xpar[0]].x2 == ln[ypar[i]].x2 &&
               ln[xpar[0]].y2 == ln[ypar[i]].y2) {
      temp.x2 = ln[ypar[i]].x1;
      temp.y2 = ln[ypar[i]].y1;
    }
  }
  if (temp.x1 == ln[xpar[1]].x1 && temp.y1 == ln[xpar[1]].y1 &&
      temp.x2 == ln[xpar[1]].x2 && temp.y2 == ln[xpar[1]].y2) {
    cout << "YES";
  } else if (temp.x2 == ln[xpar[1]].x1 && temp.y2 == ln[xpar[1]].y1 &&
             temp.x1 == ln[xpar[1]].x1 && temp.y2 == ln[xpar[1]].y2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
