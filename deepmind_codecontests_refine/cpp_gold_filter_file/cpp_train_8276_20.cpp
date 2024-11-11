#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long int x;
  cin >> x;
  long long int mn = (s[0] - '0') * 10 + (s[1] - '0');
  mn *= 60;
  mn += (s[3] - '0') * 10 + (s[4] - '0');
  mn += x;
  long long int minute = mn % 60;
  long long int hour = mn / 60;
  if (hour >= 24) {
    hour %= 24;
  }
  if (hour < 10) cout << "0";
  cout << hour << ":";
  if (minute < 10) cout << "0";
  cout << minute << endl;
  return 0;
}
