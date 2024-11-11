#include <bits/stdc++.h>
const long long int mod = 9999999999999983;
long long int primes[6] = {1125899906842597, 1495921043, 1005985879,
                           1495921043,       1005985879, 1495921043};
using namespace std;
vector<string> vect;
long long int level[1000009];
vector<string> vt[1000009];
map<string, long long int> mp;
void printWords(string str) {
  string word;
  stringstream iss(str);
  while (iss >> word) vect.push_back(word);
}
int main() {
  int start_s = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, j, k, n, m, store, mxlevel = 0;
  stack<long long int> stk;
  string str, str1;
  cin >> str;
  for (i = 0; i < str.size(); i++) {
    if (str[i] == ',') str[i] = ' ';
  }
  printWords(str);
  for (i = 0; i < vect.size(); i++) {
    str1 = vect[i];
    if (str1[0] - '0' >= 0 && str1[0] - '0' <= 9) {
      string s = str1;
      stringstream geek(s);
      long long int number = 0;
      geek >> number;
      if (number != 0) stk.push(number);
      continue;
    }
    if (stk.size() == 0)
      level[i] = 0;
    else {
      level[i] = stk.size();
      store = stk.top();
      stk.pop();
      if (store - 1 != 0) stk.push(store - 1);
      if (store - 1 == 0 && vect[i + 1] != "0") stk.push(0);
      if (store - 1 == 0 && vect[i + 1] == "0") {
        while (stk.size() > 0) {
          if (stk.top() == 0)
            stk.pop();
          else
            break;
        }
      }
    }
  }
  for (i = 0; i < vect.size(); i++) {
    str1 = vect[i];
    if (str1[0] - '0' >= 0 && str1[0] - '0' <= 9) {
      continue;
    } else {
      mxlevel = max(mxlevel, level[i]);
      vt[level[i]].push_back(vect[i]);
    }
  }
  cout << mxlevel + 1 << "\n";
  for (i = 0; i < mxlevel; i++) {
    for (j = 0; j < vt[i].size(); j++) {
      cout << vt[i][j] << " ";
    }
    cout << "\n";
  }
}
