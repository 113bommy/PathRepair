#include <bits/stdc++.h>
using namespace std;
long long int area[1000];
pair<long long int, long long int> p[1000];
vector<int> hull1, hull2, ans;
int cross(int a, int b, int c) {
  int s;
  cout << "2 " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  cin >> s;
  return s;
}
int main() {
  int i;
  int n;
  cin >> n;
  area[0] = area[1] = 0;
  for (i = 2; i < n; i++) {
    int s;
    cout << "1 1 2 " << i + 1 << endl;
    cin >> area[i];
    cout << "2 1 2 " << i + 1 << endl;
    cin >> s;
    area[i] *= s;
  }
  for (i = 0; i < n; i++) p[i] = make_pair(area[i], i);
  sort(p, p + n);
  for (i = 0; i < n; i++) {
    while ((hull1.size() >= 2) &&
           (cross(hull1[hull1.size() - 2], hull1.back(), p[i].second) == -1)) {
      hull2.push_back(hull1.back());
      hull1.pop_back();
    }
    hull1.push_back(p[i].second);
  }
  ans = hull1;
  for (i = (int)hull2.size() - 1; i >= 0; i--) ans.push_back(hull2[i]);
  for (i = 0; i < n; i++) {
    if (ans[i] == 0) break;
  }
  int x = i;
  cout << "0";
  for (i = 0; i < n; i++) cout << " " << ans[(i + x) % n] + 1;
  cout << endl;
  return 0;
}
