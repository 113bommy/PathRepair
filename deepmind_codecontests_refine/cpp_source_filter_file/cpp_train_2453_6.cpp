#include <bits/stdc++.h>
using namespace std;
const int sun = 0;
const int mon = 1;
const int tue = 2;
const int wed = 3;
const int thur = 4;
const int fri = 5;
const int sat = 6;
map<string, long long> m;
map<long long, string> rm;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T, N, i, j, k, M;
  string d1, d2;
  cin >> d1 >> d2;
  m["sunday"] = 0;
  m["monday"] = 1;
  m["tuesday"] = 2;
  m["wednesday"] = 3;
  m["thursday"] = 4;
  m["friday"] = 5;
  m["saturday"] = 6;
  rm[0] = "sunday";
  rm[1] = "monday";
  rm[2] = "tuesday";
  rm[3] = "wednesday";
  rm[4] = "thursday";
  rm[5] = "friday";
  rm[6] = "saturday";
  if (d1 == d2 || rm[(m[d1] + 3) % 7] == d2 || rm[(m[d1] + 4) % 7] == d2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
