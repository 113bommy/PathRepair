#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int a1, a2, a3, a4;
string S;
void solve() {
  cin >> a1 >> a2 >> a3 >> a4;
  if (abs(a3 - a4) > 1) {
    cout << -1;
    return;
  }
  if (max(a3, a4) > a1 || max(a3, a4) > a2) {
    cout << -1;
    return;
  }
  string temp = "";
  if (a3 > a4 || (a3 == a4 && a3 + 1 <= a1)) {
    a1--;
    S += '4';
    while (a3 || a4) {
      int temp = (int)S.size() - 1;
      if (S[temp] == '4' && a2 && a3) {
        a2--;
        a3--;
        S += '7';
        continue;
      }
      if (S[temp] == '7' && a1 && a4) {
        a4--;
        a1--;
        S += '4';
        continue;
      }
      cout << -1;
      return;
    }
    int pos = -1;
    for (int i = (int)S.size() - 1; i >= 0; i--)
      if (S[i] == '7') {
        pos = i;
        break;
      }
    if (pos == -1) {
      cout << -1;
      return;
    }
    while (a1--) temp += '4';
    cout << temp;
    temp = "";
    while (a2--) temp += '7';
    for (int i = 0; i < (int)S.size(); i++) {
      cout << S[i];
      if (i == pos) cout << temp;
    }
    return;
  }
  S = "7";
  a2--;
  while (a3 || a4) {
    int temp = (int)S.size() - 1;
    if (S[temp] == '4' && a2 && a3) {
      a2--;
      a3--;
      S += '7';
      continue;
    }
    if (S[temp] == '7' && a1 && a4) {
      a4--;
      a1--;
      S += '4';
      continue;
    }
    cout << -1;
    return;
  }
  int pos = -1;
  for (int i = 0; i < (int)S.size(); i++)
    if (S[i] == '4') {
      pos = i;
      break;
    }
  int pos2 = -1;
  for (int i = (int)S.size() - 1; i >= 0; i--)
    if (S[i] == '7') {
      pos2 = i;
      break;
    }
  if (pos == -1 || pos2 == -1) {
    cout << -1;
    return;
  }
  string temp2 = "";
  while (a2--) temp2 += '7';
  while (a1--) temp += '4';
  for (int i = 0; i < (int)S.size(); i++) {
    cout << S[i];
    if (i == pos)
      cout << temp;
    else if (i == pos2)
      cout << temp2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
