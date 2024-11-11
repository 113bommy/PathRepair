#include <bits/stdc++.h>
using namespace std;
vector<string> numbers;
int solve() {
  int n = 0;
  for (int i = 1; i < 20; i++) {
    string prefix = numbers[0].substr(0, i);
    for (vector<string>::iterator j = numbers.begin(); j != numbers.end();
         j++) {
      if ((*j)[n] != prefix[n]) {
        return n;
      }
    }
    n++;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    numbers.push_back(s);
  }
  cout << solve() << endl;
  return 0;
}
