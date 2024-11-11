#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> chain;
int result = 0;
int main() {
  string name1, name2;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  chain["polycapr"] = 1;
  for (int i = 0; i < n; i++) {
    cin >> name1 >> name2 >> name2;
    transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
    transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
    chain[name1] = max(chain[name1], chain[name2] + 1);
  }
  for (map<string, int>::iterator it = chain.begin(); it != chain.end(); it++)
    result = max(result, it->second);
  cout << result << "\n";
  return 0;
}
