#include <bits/stdc++.h>
using namespace std;
string myreverse(string a) {
  string b = "";
  for (int i = a.size() - 1; i >= 0; i--) b += a[i];
  return b;
}
string substring(string a, int start, int end) {
  string h = "";
  for (int i = start; i < end; i++) h += a[i];
  return h;
}
int htoi(string a) {
  int ans = 0;
  for (int i = 0; i < a.length(); i++)
    ans += pow(10, a.length() - i - 1) * (a[i] - 48);
  return ans;
}
string itoh(int a) {
  string ans = "";
  while (a >= 10) {
    ans += (a % 10) + 48;
    a /= 10;
  }
  ans += a + 48;
  return myreverse(ans);
}
int main() {
  string a;
  cin >> a;
  int hour = htoi(substring(a, 0, 2)), minutes = htoi(substring(a, 3, 5));
  while (true) {
    minutes++;
    if (minutes == 60) {
      hour++;
      if (hour == 24) hour = 0;
      minutes = 0;
    }
    string m = itoh(minutes), ho = itoh(hour);
    if (m.length() == 1) {
      m += '0';
      m = myreverse(m);
    }
    if (ho.length() == 1) {
      ho += '0';
      ho = myreverse(ho);
    }
    string h = ho + ':' + m;
    string l = myreverse(h);
    if (h == l) {
      cout << h << endl;
      return 0;
    }
  }
}
