#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> vSum(N);
int main() {
  string s1;
  ifstream ff("file.txt");
  cin >> s1;
  s1 = '*' + s1;
  char c = '1';
  for (int i = 1; i < s1.length(); i++) {
    if (tolower(s1[i]) == 'a' || tolower(s1[i]) == 'e' ||
        tolower(s1[i]) == 'i' || tolower(s1[i]) == 'o' ||
        tolower(s1[i]) == 'u') {
      vSum[i] = -1;
    } else {
      vSum[i] = 2;
    }
    vSum[i] += vSum[i - 1];
  }
  map<int, int> m1;
  map<int, int>::iterator p;
  int Max = -1, kol = 0, sum;
  for (int i = 1; i < s1.length(); i++) {
    if (vSum[i] >= 0) {
      if (i > Max) {
        kol = 1;
        Max = i;
      }
    } else {
      int t = vSum[i];
      p = m1.find(t);
      if (p != m1.end()) {
        sum = i - p->second;
        if (sum == Max) {
          kol++;
        } else if (sum > Max) {
          kol = 1;
          Max = sum;
        }
      } else {
        m1[vSum[i]] = i;
      }
    }
  }
  if (Max == -1) {
    cout << "No solution" << endl;
    return 0;
  } else {
    cout << Max << ' ' << kol << endl;
  }
  return 0;
}
