#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000000;
const int N = 200100;
int n, m;
pair<int, int> pp[N];
pair<int, int> diagl[N];
pair<int, int> diagr[N];
pair<int, int> bdiagl[N];
pair<int, int> bdiagr[N];
pair<int, int> rowl[N];
pair<int, int> rowr[N];
pair<int, int> coll[N];
pair<int, int> colr[N];
int rec[8];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int i;
    memset(rec, 0, sizeof(rec));
    for (i = 0; i < 2 * n + 2; i++) {
      diagl[i].first = -1;
      diagr[i].first = oo;
      bdiagl[i].first = oo;
      bdiagr[i].first = -1;
      rowl[i].first = oo;
      rowr[i].first = -1;
      coll[i].second = oo;
      colr[i].second = -1;
    }
    for (i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      pp[i].first = x;
      pp[i].second = y;
      if (x > diagl[x + y].first) {
        diagl[x + y].first = x;
        diagl[x + y].second = y;
      }
      if (x < diagr[x + y].first) {
        diagr[x + y].first = x;
        diagr[x + y].second = y;
      }
      if (x < bdiagl[n + (x - y)].first) {
        bdiagl[n + (x - y)].first = x;
        bdiagl[n + (x - y)].second = y;
      }
      if (x > bdiagr[n + (x - y)].first) {
        bdiagr[n + (x - y)].first = x;
        bdiagr[n + (x - y)].second = y;
      }
      if (x < rowl[y].first) {
        rowl[y].first = x;
        rowl[y].second = y;
      }
      if (x > rowr[y].first) {
        rowr[y].first = x;
        rowr[y].second = y;
      }
      if (y < coll[x].second) {
        coll[x].first = x;
        coll[x].second = y;
      }
      if (y > colr[x].second) {
        colr[x].first = x;
        colr[x].second = y;
      }
    }
    for (i = 0; i < m; i++) {
      int x = pp[i].first;
      int y = pp[i].second;
      int cnt = 0;
      if (diagl[x + y].first > x) cnt++;
      if (diagr[x + y].first < x) cnt++;
      if (bdiagl[n + (x - y)].first < x) cnt++;
      if (bdiagr[n + (x - y)].first > x) cnt++;
      if (rowl[y].first < x) cnt++;
      if (rowr[y].first > x) cnt++;
      if (coll[x].second < y) cnt++;
      if (colr[x].second > y) cnt++;
      rec[cnt]++;
    }
    for (i = 0; i < 7; i++) printf("%d ", rec[i]);
    printf("%d\n", rec[i]);
  }
}
