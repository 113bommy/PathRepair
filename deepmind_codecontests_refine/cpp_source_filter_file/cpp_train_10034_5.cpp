#include <bits/stdc++.h>
using namespace std;
bool ok[12];
bool there[258][12];
int len[258];
string toString(int);
string swapString(string);
int toNum(string);
bool cekPalindrome(string);
int main(void) {
  set<string> ans;
  int n;
  scanf("%d", &n);
  if (n > 6) {
    printf("0\n");
    return 0;
  }
  while (n--) {
    int a;
    scanf("%d", &a);
    ok[a] = true;
  }
  for (int i = 0; i < 256; i++) {
    int buff;
    buff = i;
    if (i == 0) {
      there[buff][0] = true;
      len[buff] = 1;
    } else {
      while (buff != 0) {
        len[i]++;
        there[i][buff % 10] = true;
        buff /= 10;
      }
    }
  }
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      for (int z = 0; z < 256; z++) {
        bool able = true;
        for (int k = 0; k < 10; k++) {
          if ((there[i][k] | there[j][k] | there[z][k]) != ok[k]) {
            able = false;
            break;
          }
        }
        if (able) {
          string a, b, c, wew, lala;
          a = toString(i);
          b = toString(j);
          c = toString(z);
          wew = a + b + c;
          lala = "";
          for (int k = 0; k < 3; k++) {
            lala = wew[k] + lala;
            if (toNum(lala) > 256) continue;
            if (k > 0 && lala[0] == '0') continue;
            if (cekPalindrome(wew + lala))
              ans.insert(a + "." + b + "." + c + "." + lala);
          }
        }
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
    cout << *it << endl;
  return 0;
}
string toString(int x) {
  if (x == 0) return "0";
  string ans = "";
  while (x != 0) {
    ans = ((char)((x % 10) + '0')) + ans;
    x /= 10;
  }
  return ans;
}
string swapString(string x) {
  string ans = "";
  for (int i = x.length() - 1; i >= 0; i--) ans += x[i];
  return ans;
}
int toNum(string x) {
  int ans = 0;
  for (int i = 0; i < x.length(); i++) ans = ans * 10 + (x[i] - '0');
  return ans;
}
bool cekPalindrome(string x) {
  for (int i = 0; i < x.length(); i++)
    if (x[i] != x[x.length() - i - 1]) return false;
  return true;
}
