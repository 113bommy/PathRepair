#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  long long mn;
  cin >> mn;
  unordered_map<string, long long> mtoi;
  unordered_map<long long, string> itom;
  mtoi["January"] = 1;
  mtoi["February"] = 2;
  mtoi["March"] = 3;
  mtoi["April"] = 4;
  mtoi["May"] = 5;
  mtoi["June"] = 6;
  mtoi["July"] = 7;
  mtoi["August"] = 8;
  mtoi["September"] = 9;
  mtoi["October"] = 10;
  mtoi["November"] = 11;
  mtoi["December"] = 12;
  itom[1] = "January";
  itom[2] = "February";
  itom[3] = "March";
  itom[4] = "April";
  itom[5] = "May";
  itom[6] = "June";
  itom[7] = "July";
  itom[8] = "August";
  itom[9] = "September";
  itom[10] = "October";
  itom[11] = "November";
  itom[12] = "December";
  long long n = mtoi[str];
  n += mn;
  if (n % 2 == 0)
    cout << itom[12] << endl;
  else
    cout << itom[n % 12] << endl;
  return 0;
}
