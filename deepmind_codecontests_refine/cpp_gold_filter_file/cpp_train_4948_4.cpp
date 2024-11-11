#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 200200;
vector<int> v1;
vector<int> v2;
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t) v1.push_back(t);
  }
  for (int i = 0; i < n - 1; i++) {
    v1.push_back(v1[i]);
  }
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t) v2.push_back(t);
  }
  for (int i = 0; i < n - 1; i++) {
    v2.push_back(v2[i]);
  }
  int i = 0, counter = 0;
  bool flag = false, ans = false;
  for (int k = 0; k < v1.size(); k++) {
    if (counter == n - 1) break;
    if (v2[i] == v1[k]) {
      flag = true;
      counter++;
      i++;
    } else if (v2[i] != v1[k] and flag) {
      break;
    }
  }
  if (counter == n - 1) ans = true;
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
