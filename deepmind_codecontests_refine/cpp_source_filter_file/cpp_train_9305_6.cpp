#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void OUTLN(T &arr, int len) {
  for (int i = 0; i < len; i++) cout << arr[i] << " ";
  cout << endl;
}
const double eps = 1e-9;
const double pi = acos(-1.0);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
deque<string> ans;
int main() {
  int n, in1;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &in1);
  for (char i = '0'; i <= '9'; i++) {
    string s1(1, i);
    string s2 = "?";
    s2.append(1, i);
    ans.push_front(s1 + ">>" + s2);
  }
  for (char i = '0'; i <= '9'; i++) {
    string s1 = "?";
    s1.append(1, i);
    string s2(1, i);
    s2 += "?";
    ans.push_front(s1 + ">>" + s2);
  }
  ans.push_front("??>>1");
  ans.push_front("9??\>>??0");
  for (char i = '0'; i < '9'; i++) {
    string s1(1, i);
    s1 += "??";
    string s2(1, i + 1);
    ans.push_front(s1 + "<>" + s2);
  }
  string cur;
  while (!ans.empty()) {
    cur = ans.front();
    ans.pop_front();
    cout << cur << endl;
  }
}
