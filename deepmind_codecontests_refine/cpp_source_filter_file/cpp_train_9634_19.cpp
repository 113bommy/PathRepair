#include <bits/stdc++.h>
using namespace std;
void i_can() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  i_can();
  long long int n, m, i, j, k;
  cin >> n >> m;
  long long int len_hrs = 0, len_mins = 0;
  for (i = 7; i < n; i *= 7) len_hrs++;
  for (i = 7; i < m; i *= 7) len_mins++;
  long long int cnt = 0;
  if (len_mins + len_hrs <= 7) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        vector<long long int> used(7);
        long long int a = i;
        long long int b = j;
        for (k = 0; k < len_hrs; k++) {
          used[a % 7] += 1;
          a /= 7;
        }
        for (k = 0; k < len_mins; k++) {
          used[b % 7] += 1;
          b /= 7;
        }
        if (*max_element(used.begin(), used.end()) <= 1) ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
