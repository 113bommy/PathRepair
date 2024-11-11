#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<pair<int, int> > mark;
int ans[MAXN];
int main() {
  string months[] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
  string w;
  cin >> w;
  int k;
  cin >> k;
  int i;
  for (i = 0; i < 12; i++) {
    if (months[i] == w) break;
  }
  i += k;
  i %= 12;
  cout << months[i] << endl;
}
