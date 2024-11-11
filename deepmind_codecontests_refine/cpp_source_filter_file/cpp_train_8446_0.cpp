#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
int checkType(int n) {
  if (n <= 2) return 0;
  if (n <= 4) return 1;
  if (n <= 6) return 2;
}
int CheckWord(string s) {
  int n = s.length();
  if (n < 3) return -1;
  if (n >= 3) {
    string p = s.substr(n - 3);
    if (p.compare("etr") == 0)
      return 3;
    else if (n == 3)
      return -1;
  }
  if (n >= 4) {
    string p = s.substr(n - 4);
    if (p.compare("lios") == 0) return 1;
    if (p.compare("etra") == 0) return 4;
    if (n == 4) return -1;
  }
  if (n >= 5) {
    string p = s.substr(n - 5);
    if (p.compare("liala") == 0)
      return 2;
    else if (n == 5)
      return -1;
  }
  if (n >= 6) {
    string p = s.substr(n - 6);
    if (p.compare("initis") == 0) return 5;
    if (p.compare("inites") == 0)
      return 6;
    else
      return -1;
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  ;
  string s;
  string wd = "";
  getline(cin, s);
  s += " ";
  std::vector<string> words;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ')
      wd += s[i];
    else {
      words.push_back(wd);
      wd = "";
    }
  }
  if ((int)(words.size()) == 1) {
    string c = words[0];
    int res = CheckWord(c);
    if (res == -1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return 0;
  }
  int check = CheckWord(words[0]);
  int gender = check & 1;
  int curr = checkType(check);
  if (curr != 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i < words.size(); i++) {
    check = CheckWord(words[i]);
    if (check == -1) {
      cout << "NO" << endl;
      return 0;
    }
    int checkcurr = checkType(check);
    if (checkcurr < curr) {
      cout << "NO" << endl;
      return 0;
    }
    if (checkcurr > (curr + 1)) {
      cout << "NO" << endl;
      return 0;
    }
    if (curr == 1 && checkcurr == 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (gender != (check & 1)) {
      cout << "NO" << endl;
      return 0;
    }
    curr = checkcurr;
  }
  if (curr == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
