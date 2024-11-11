#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000050;
int abs(int x) { return (x > 0) ? x : -x; }
int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  bool ok = true;
  ok &= (a3 <= a1 && a3 <= a2);
  ok &= (a4 <= a1 && a4 <= a2);
  ok &= (abs(a3 - a4) <= 1);
  ok &= ((a3 != a4) or ((a4 + 1 <= a1) or (a4 + 1 <= a2)));
  if (ok) {
    string S;
    if (a3 > a4) {
      for (int i = 0; i < a3; i++) {
        S.push_back('4');
        S.push_back('7');
      }
      a1 -= a3;
      a2 -= a3;
      string beforeStr;
      for (int i = 0; i < a1; i++) {
        beforeStr.push_back('4');
      }
      S = beforeStr + S;
      string afterStr;
      for (int i = 0; i < a2; i++) {
        afterStr.push_back('7');
      }
      S = S + afterStr;
    } else if (a4 > a3) {
      for (int i = 0; i < a4; i++) {
        S.push_back('7');
        S.push_back('4');
      }
      a1 -= a4;
      a2 -= a4;
      string beforeStr;
      for (int i = 0; i < a1; i++) {
        beforeStr.push_back('4');
      }
      string afterStr;
      for (int i = 0; i < a2; i++) {
        afterStr.push_back('7');
      }
      S.insert(1, beforeStr);
      int length = S.size();
      S.insert(length - 1, afterStr);
    } else {
      if (a4 + 1 <= a1) {
        for (int i = 0; i < a4; i++) {
          S.push_back('4');
          S.push_back('7');
        }
        S.push_back('4');
        a1 -= a4 + 1;
        a2 -= a4;
        string beforeStr;
        for (int i = 0; i < a1; i++) {
          beforeStr.push_back('4');
        }
        string afterStr;
        for (int i = 0; i < a2; i++) {
          afterStr.push_back('7');
        }
        int length = S.size();
        S.insert(length - 1, afterStr);
        S = beforeStr + S;
      } else if (a4 + 1 <= a2) {
        for (int i = 0; i < a4; i++) {
          S.push_back('7');
          S.push_back('4');
        }
        S.push_back('7');
        a1 -= a4;
        a2 -= a4 + 1;
        string beforeStr;
        for (int i = 0; i < a1; i++) {
          beforeStr.push_back('4');
        }
        string afterStr;
        for (int i = 0; i < a2; i++) {
          afterStr.push_back('7');
        }
        S.insert(1, beforeStr);
        int length = S.size();
        S.insert(length - 1, afterStr);
      }
    }
    cout << S << endl;
  } else {
    cout << -1 << endl;
  }
}
