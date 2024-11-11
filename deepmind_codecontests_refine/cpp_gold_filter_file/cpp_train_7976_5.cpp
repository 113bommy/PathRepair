#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const string s[2] = {"typedef", "typeof"};
struct var {
  string name;
  int num;
};
int N;
int vart = 1;
var t[maxn];
string order;
bool flag;
bool flag2;
int findTof(string input) {
  int num1 = 0;
  int T = 0;
  flag = true;
  flag2 = true;
  while (input[num1] == '&') --T, ++num1;
  int num2 = input.length() - 1;
  while (input[num2] == '*') ++T, --num2;
  string v = "";
  for (int i = num1; i <= num2; ++i) v += input[i];
  for (int i = 0; i < vart; ++i) {
    if (v == t[i].name) {
      T += t[i].num;
      flag2 = false;
      if (t[i].num < 0) flag = false;
      break;
    }
  }
  return T;
}
void Defin() {
  cin >> order;
  int T = findTof(order);
  int numofme = -1;
  cin >> order;
  for (int i = 0; i < vart; i++)
    if (t[i].name == order) {
      numofme = i;
    }
  if (numofme < 0) numofme = vart, vart++;
  if (!flag || flag2)
    t[numofme].num = -100;
  else
    t[numofme].num = T;
  t[numofme].name = order;
}
void Print() {
  cin >> order;
  int T = findTof(order);
  if (T < 0 || flag2 || !flag) {
    cout << "errtype" << endl;
    return;
  }
  cout << "void";
  for (int i = 0; i < T; i++) cout << "*";
  cout << endl;
}
int main() {
  t[0].num = 0;
  t[0].name = "void";
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> order;
    if (order == s[0])
      Defin();
    else
      Print();
  }
  return 0;
}
