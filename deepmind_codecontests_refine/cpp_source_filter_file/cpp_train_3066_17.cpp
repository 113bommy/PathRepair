#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<string> plant_names;
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    plant_names.insert(s1 + s2);
  }
  cout << plant_names.size() << endl;
}
