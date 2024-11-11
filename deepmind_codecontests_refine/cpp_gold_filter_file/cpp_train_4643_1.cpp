#include <bits/stdc++.h>
using namespace std;
long long int n;
string s;
vector<pair<char, long long int>> sor;
stack<char> t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  for (long long int i = 0; i < (long long int)s.size(); ++i)
    sor.push_back(make_pair(s[i], i));
  stable_sort(sor.begin(), sor.end());
  long long int counter = 0;
  auto iter = sor.begin();
  while (iter != sor.end()) {
    if (!t.empty() && t.top() <= iter->first) {
      cout << t.top();
      t.pop();
      continue;
    }
    while (counter <= iter->second) {
      t.push(s[counter]);
      counter++;
    }
    if (counter - 1 == iter->second) {
      cout << t.top();
      t.pop();
    }
    iter++;
  }
  while (!t.empty()) {
    cout << t.top();
    t.pop();
  }
  return 0;
}
