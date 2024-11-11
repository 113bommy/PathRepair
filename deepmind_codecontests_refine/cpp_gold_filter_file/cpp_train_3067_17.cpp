#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  vector<string> str;
  int n;
  cin >> n;
  int t = n;
  for (int i = 0; i < n; i++) {
    string t, c;
    cin >> t >> c;
    str.push_back(t + " " + c);
  }
  sort(str.begin(), str.end());
  cout << distance(str.begin(), unique(str.begin(), str.begin() + t));
  return 0;
}
