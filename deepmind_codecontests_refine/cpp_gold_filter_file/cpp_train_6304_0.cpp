#include <bits/stdc++.h>
using namespace std;
char ret[210000];
long long addO;
long long dot;
void round(long long& re) {
  while (ret[re] > '9') {
    ret[re] = '0';
    re--;
    if (re < 0) {
      addO = 1;
      break;
    }
    if (re == dot) re--;
    ret[re]++;
  }
}
void run() {
  long long n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) ret[i] = s[i];
  long long i = 0;
  for (; s[i] != '.'; i++)
    ;
  dot = i;
  long long re = -1;
  for (; i < s.size() - 1; i++) {
    if (s[i + 1] >= '5') {
      re = i;
      break;
    }
  }
  if (re == -1) {
    cout << s << endl;
    return;
  }
  addO = 0;
  ret[re + 1] = 0;
  if (re != dot)
    ret[re]++;
  else {
    re--;
    ret[re]++;
  }
  round(re);
  re--;
  t--;
  while (re >= dot && t) {
    if (ret[re + 1] >= '5') {
      ret[re + 1] = 0;
      if (re != dot)
        ret[re]++;
      else {
        re--;
        ret[re]++;
      }
      round(re);
      t--;
    }
    re--;
  }
  if (re < dot - 1) ret[dot] = 0;
  if (addO) cout << "1";
  cout << ret << endl;
}
int main() { run(); }
