#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int answer = 0;
  for (int i = s.length() - 1; i > 0; i--) {
    string temp = s.substr(i - 1, 2);
    if (stoi(temp) % 4 == 0) {
      answer += i;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (stoi(s.substr(i, 1)) % 4 == 0) {
      answer++;
    }
  }
  cout << answer;
}
