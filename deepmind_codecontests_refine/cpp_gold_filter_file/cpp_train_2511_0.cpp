#include <bits/stdc++.h>
using namespace std;
int n, m;
long long y;
int prof_at_seat[17];
int seat_of_prof[17];
int before_seat[17];
long long dp[(1 << 17)];
long long ways(int mask_of_seats) {
  int prof = __builtin_popcount(mask_of_seats);
  if (prof >= n) return 1;
  if (dp[mask_of_seats] != -1) return dp[mask_of_seats];
  long long w = 0;
  for (int seat = 0; seat < n; seat++) {
    if ((mask_of_seats & (1 << seat)) != 0) continue;
    if (prof_at_seat[seat] != -1 && prof_at_seat[seat] != prof) continue;
    if (seat_of_prof[prof] != -1 && seat_of_prof[prof] != seat) continue;
    if ((mask_of_seats & before_seat[seat]) != before_seat[seat]) continue;
    w += ways(mask_of_seats | (1 << seat));
  }
  return dp[mask_of_seats] = w;
}
int main() {
  scanf("%d", &n);
  cin >> y;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    a--;
    b--;
    before_seat[b] |= (1 << a);
  }
  for (int i = 0; i < n; i++) {
    seat_of_prof[i] = -1;
    prof_at_seat[i] = -1;
  }
  y -= 2001;
  memset(dp, -1, sizeof dp);
  long long ww = ways(0);
  if (ww <= y) {
    cout << "The times have changed" << endl;
    return 0;
  }
  for (int seat = 0; seat < n; seat++) {
    for (int prof = 0; prof < n; prof++) {
      if (seat_of_prof[prof] != -1) continue;
      seat_of_prof[prof] = seat;
      prof_at_seat[seat] = prof;
      memset(dp, -1, sizeof dp);
      long long w = ways(0);
      if (w <= y) {
        y -= w;
        prof_at_seat[seat] = -1;
        seat_of_prof[prof] = -1;
      } else {
        break;
      }
    }
    printf("%d ", prof_at_seat[seat] + 1);
  }
  cout << endl;
  return 0;
}
