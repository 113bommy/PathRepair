#include <bits/stdc++.h>
using namespace std;
bool ch[100001];
void sieve() {
  memset(ch, false, sizeof(ch));
  for (int i = 2; i <= sqrt(100001); i++) {
    if (ch[i] == false) {
      for (int j = i * i; j <= 100000; j += i) ch[j] = true;
    }
  }
}
long long val(long long no) {
  long long sum = 0;
  while (no) {
    sum = sum + no % 10;
    no /= 10;
  }
  return sum;
}
int main() {
  string good, str;
  cin >> good >> str;
  bool ch[200];
  memset(ch, false, sizeof(ch));
  for (auto x : good) ch[x] = true;
  int coun[27];
  memset(coun, 0, sizeof(coun));
  for (auto x : str) {
    if (x >= 'a' && x <= 'z') {
      if (ch[x] == false) coun[x - 97]++;
    }
  }
  int s = str.size();
  int n;
  cin >> n;
  while (n--) {
    string fin;
    cin >> fin;
    bool flag = true;
    int sz = fin.size();
    int i = 0, j = 0;
    int ct = 0;
    int count[27];
    memset(count, 0, sizeof(count));
    if (sz < (s - 1)) flag = false;
    if (flag) {
      for (auto x : fin) {
        if (x >= 'a' && x <= 'z') {
          if (ch[x] == false) count[x - 97]++;
        }
      }
      for (int i = 0; i < 27; i++) {
        ct = ct + abs(count[i] - coun[i]);
      }
      for (; i < sz && j < s;) {
        if (str[j] == '?') {
          if (ch[fin[i]] == false) {
            flag = false;
            break;
          }
          i++, j++;
        } else if (str[j] == '*') {
          if (sz >= str.size()) {
            while (i < sz && ch[fin[i]] == false && ct > 0) {
              ct--;
              i++;
            }
          }
          j++;
        } else {
          if (fin[i] != str[j]) flag = false;
          i++;
          j++;
        }
      }
    }
    if (i < sz || j < s - 1) flag = false;
    if (j == (s - 1) && str[j] != '*') flag = false;
    if (flag)
      cout << "YES \n";
    else
      cout << "NO \n";
  }
  return 0;
}
