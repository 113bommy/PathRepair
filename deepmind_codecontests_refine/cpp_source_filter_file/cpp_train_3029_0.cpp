#include <bits/stdc++.h>
using namespace std;
string second, t;
vector<pair<int, int> > strA, strB;
bool swp;
int calc(int a, int b, int sm) {
  if (a < b) swap(a, b);
  if (sm) {
    return max(a - 1, b + 1);
  } else {
    return a - 1;
  }
}
pair<int, int> lstA() { return strA[strA.size() - 1]; }
pair<int, int> lstB() { return strB[strB.size() - 1]; }
void opt(int x, int y) {
  if (swp)
    cout << y << " " << x << "\n";
  else
    cout << x << " " << y << "\n";
}
void insA(pair<int, int> toIns) {
  if (lstA().first == toIns.first) {
    strA[strA.size() - 1].second += toIns.second;
  } else {
    strA.push_back(toIns);
  }
}
void insB(pair<int, int> toIns) {
  if (lstB().first == toIns.first) {
    strB[strB.size() - 1].second += toIns.second;
  } else {
    strB.push_back(toIns);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> second >> t;
  int stk = 0;
  int pv = second[second.size() - 1] - 'a';
  for (int i = (second.size() - 1); i >= 0; i--) {
    if (second[i] - 'a' != pv) {
      strA.push_back({pv, stk});
      pv = second[i] - 'a';
      stk = 1;
    } else {
      stk++;
    }
  }
  strA.push_back({pv, stk});
  stk = 0;
  pv = t[t.size() - 1] - 'a';
  for (int i = (t.size() - 1); i >= 0; i--) {
    if (t[i] - 'a' != pv) {
      strB.push_back({pv, stk});
      pv = t[i] - 'a';
      stk = 1;
    } else {
      stk++;
    }
  }
  strB.push_back({pv, stk});
  if (strA.size() < strB.size()) {
    swap(strA, strB);
    swp = !swp;
  }
  int n = strA.size();
  int m = strB.size();
  int op1 = calc(n, m, strA[n - 1].first == strB[m - 1].first);
  int op2 = 0x3f3f3f3f;
  int loc2 = -1;
  for (int i = (1); i <= (signed)(n - 1); i++) {
    int nn = n - i;
    int nm = m + i - 1 + (strA[n - i].first != strB[m - 1].first);
    bool nsm = (strA[n - i - 1].first == strA[n - 1].first);
    int res = calc(nn, nm, nsm) + 1;
    if (res < op2) {
      op2 = res;
      loc2 = i;
    }
  }
  int op3 = 0x3f3f3f3f;
  int loc3 = -1;
  for (int i = (1); i <= (signed)(n - 1); i++) {
    int nn = n - i + (strA[n - 1 - i].first != strB[m - 1].first);
    int nm = m + i - 1 - 1 + (m == 1 || strA[n - i].first != strB[m - 2].first);
    bool nsm = strA[n - 1].first == strB[m - 1].first;
    int res = calc(nn, nm, nsm) + 1;
    if (res < op3) {
      op3 = res;
      loc3 = i;
    }
  }
  if (op1 <= op2 && op1 <= op3) {
    cout << op1 << "\n";
  } else if (op2 <= op1 && op2 <= op3) {
    cout << op2 << "\n";
    int sm = 0;
    for (int i = (n - 1); i >= n - loc2; i--) {
      sm += strA[i].second;
    }
    opt(sm, 0);
    for (int i = (n - loc2); i <= (signed)(n - 1); i++) {
      insB(strA[i]);
    }
    for (int _ = 0; _ < (signed)(loc2); _++) strA.pop_back();
  } else {
    cout << op3 << "\n";
    int sm = 0;
    for (int i = (n - 1); i >= n - loc3; i--) {
      sm += strA[i].second;
    }
    opt(sm, strB[m - 1].second);
    pair<int, int> tmp = strB[m - 1];
    strB.pop_back();
    for (int i = (n - loc3); i <= (signed)(n - 1); i++) {
      insB(strA[i]);
    }
    for (int _ = 0; _ < (signed)(loc3); _++) strA.pop_back();
    insA(tmp);
  }
  if (strA.size() < strB.size()) {
    swp = !swp;
    swap(strA, strB);
  }
  if (lstA().first == lstB().first) {
    opt(lstA().second, 0);
    insB(lstA());
    strA.pop_back();
  }
  if (strA.size() < strB.size()) {
    swp = !swp;
    swap(strA, strB);
  }
  while (strA.size() != 1) {
    opt(lstA().second, lstB().second);
    pair<int, int> tmp = lstA();
    strA.pop_back();
    insA(lstB());
    strB.pop_back();
    insB(tmp);
  }
  return 0;
}
