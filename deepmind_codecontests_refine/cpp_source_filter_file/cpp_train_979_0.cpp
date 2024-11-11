#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec;
  int s1 = 0, s2 = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int br;
    cin >> br;
    for (int i = 0; i < br / 2; i++) {
      int a;
      cin >> a;
      s1 += a;
    }
    if (br % 2) {
      int a;
      cin >> a;
      vec.push_back(a);
    }
    for (int i = 0; i < br / 2; i++) {
      int a;
      cin >> a;
      s2 += a;
    }
  }
  sort(vec.begin(), vec.end());
  for (int i = vec.size(); i >= 0; i--)
    if ((vec.size() - i) % 2)
      s1 += vec[i];
    else
      s2 += vec[i];
  cout << s1 << " " << s2 << endl;
  return 0;
}
