#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> sizes;
  sizes.push_back("S");
  sizes.push_back("M");
  sizes.push_back("L");
  sizes.push_back("XL");
  sizes.push_back("XXL");
  vector<string>::iterator it;
  vector<int>::iterator ite;
  map<int, int> si;
  for (int i = 0; i < 5; i++) {
    cin >> si[i];
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    it = find(sizes.begin(), sizes.end(), a);
    int k = distance(sizes.begin(), it);
    pair<int, int> mini = pair<int, int>(12345, 0);
    for (int b = 0; b < 5; b++) {
      if (si[b] != 0) {
        int d = b - k;
        if (abs(d) <= mini.first && b > mini.second) {
          mini.first = abs(d);
          mini.second = b;
        }
      }
    }
    si[mini.second]--;
    cout << sizes[mini.second] << "\n";
  }
  return 0;
}
