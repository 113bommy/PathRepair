#include <bits/stdc++.h>
using namespace std;
vector<int> vec, vec1;
int main() {
  int t, n, m, k, num;
  scanf("%d %d %d", &n, &m, &k);
  vec.clear();
  vec1.clear();
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    vec.push_back(num);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &num);
    vec1.push_back(num);
  }
  sort(vec.begin(), vec.end());
  sort(vec1.begin(), vec1.end());
  int ans;
  if (n >= m)
    cout << "YES\n";
  else {
    int nxt = 0;
    ans = 0;
    while (!vec.empty()) {
      int num1 = vec.back();
      int num2 = vec1.back();
      vec.pop_back();
      vec1.pop_back();
      if (num1 > num2) {
        ans = 1;
        break;
      }
      nxt++;
    }
    if (ans == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
