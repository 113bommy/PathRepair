#include <bits/stdc++.h>
using namespace std;
string s, ans = "";
vector<string> numbers;
vector<string> word;
bool is_number(string s) {
  long long c = 0;
  if (s == "0") return 1;
  if (s == "") return 0;
  if (s[0] == '0') c++;
  for (long long i = 0; i < s.length(); i++) {
    if (isdigit(s[i])) c++;
  }
  return c == s.length();
}
void solve(string s) {
  string temp = "";
  long long j = 0, i = 0;
  for (; i < s.length(); i++) {
    if (s[i] != ',' && s[i] != ';') continue;
    temp = s.substr(j, i - j);
    (is_number(temp) ? numbers.push_back(temp) : word.push_back(temp));
    j = i + 1;
  }
  temp = s.substr(j, i);
  (is_number(temp) ? numbers.push_back(temp) : word.push_back(temp));
  if (numbers.size() == 0)
    cout << '-' << endl;
  else {
    string n = "";
    for (long long i = 0; i < numbers.size(); i++) {
      n += numbers[i];
      if (i == numbers.size() - 1) continue;
      n += ',';
    }
    cout << '"' << n << '"' << endl;
  }
  if (word.size() == 0)
    cout << '-' << endl;
  else {
    string w = "";
    for (long long i = 0; i < word.size(); i++) {
      w += word[i];
      if (i == word.size() - 1) continue;
      w += ',';
    }
    cout << '"' << w << '"' << endl;
  }
}
int main() {
  cin >> s;
  solve(s);
  return 0;
}
