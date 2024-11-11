#include <bits/stdc++.h>
using namespace std;
string dic[6] = {"lios", "liala", "etr", "etra", "initis", "inites"};
int com(string a, string b) {
  if (a.size() < b.size()) return 0;
  for (int i = 0; i < b.size(); i++) {
    if (a[a.size() - b.size() + i] != b[i]) return 0;
  }
  return 1;
}
int main() {
  string str;
  int ans = 1;
  int pre = -1;
  int nn = 0;
  int num = 0;
  while (cin >> str) {
    num++;
    if (!ans) {
      continue;
    }
    int pos = -1;
    for (int i = 0; i < 6; i++) {
      if (com(str, dic[i])) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      ans = 0;
      continue;
    }
    if (pos == 2 || pos == 3) nn++;
    if (nn > 1) {
      ans = 0;
      continue;
    }
    if (pre != -1 && pos % 2 != pre % 2) {
      ans = 0;
      continue;
    }
    if (pos < pre) {
      ans = 0;
      continue;
    }
    pre = pos;
  }
  if (num > 1 && nn != 1) {
    ans = 0;
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
