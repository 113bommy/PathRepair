#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 15;
const int N = 1e5 + 4;
using namespace std;
long long whole, digit;
void Eleemnt3(string a) {
  vector<long long> sum(2, 0);
  int k = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '.' && i < a.size() - 3) continue;
    if (a[i] == '.' && i == a.size() - 3) {
      k = 1;
      continue;
    }
    sum[k] = sum[k] * 10 + a[i] - '0';
  }
  whole += sum[0];
  digit += sum[1];
}
int main() {
  {}
  string s;
  cin >> s;
  int i = 0;
  while (i < s.size()) {
    int j = i;
    while (j < s.size() && (isdigit(s[j]) || s[j] == '.')) j++;
    string temp;
    if (i != j) temp = s.substr(i, j - i);
    if (temp.size()) {
      Eleemnt3(temp);
      i = j;
    }
    ++i;
  }
  if (digit > 99) {
    whole += (digit - 99);
    digit = 99;
  }
  string res = "";
  int count = 0;
  while (whole > 0) {
    if (count % 3 == 0 && count > 0) res = '.' + res;
    char temp = whole % 10 + '0';
    res = temp + res;
    whole /= 10;
    count++;
  }
  if (res == "") res = "0";
  cout << res;
  if (digit != 0) {
    cout << '.';
    if (digit < 10)
      cout << 0 << digit;
    else
      cout << digit;
  }
  cout << endl;
  return 0;
}
