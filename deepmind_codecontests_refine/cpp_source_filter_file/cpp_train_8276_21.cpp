#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  long long int n;
  cin >> n;
  long long int h = n / 60;
  long long int m = n - h * 60;
  int hh = h % 24;
  string k = "";
  k += s[0];
  k += s[1];
  int kk = atoi(k.c_str());
  string min = "";
  min += s[3];
  min += s[4];
  int minn = atoi(min.c_str());
  kk = (kk + hh + (minn + m > 60)) % 24;
  minn = (minn + m) % 60;
  cout << (kk < 10 ? "0" : "") << kk << ":" << (minn < 10 ? "0" : "") << minn
       << endl;
  return 0;
}
