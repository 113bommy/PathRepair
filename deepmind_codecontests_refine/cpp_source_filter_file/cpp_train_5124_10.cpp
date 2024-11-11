#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  int x;
  int y;
  int move;
  Point(int x, int y, int m) {
    this->x = x;
    this->y = y;
    move = m;
  }
  bool operator==(const Point& p) const {
    return (this->x == p.x) && (this->y == p.y);
  }
};
class Hash {
 public:
  size_t operator()(const Point& p) const {
    long long h = p.x + 200000;
    h = h + (p.y + 200000) * 1000000;
    return h;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      char c = str[i];
      if (c == 'A') arr.push_back(i);
    }
    int size = arr.size();
    int max = 0;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i + 1] - arr[i] - 1 > max) max = arr[i + 1] - arr[i];
    }
    if (size != 0 && n - 1 - arr[size - 1] > max) max = n - 1 - arr[size - 1];
    cout << max << endl;
  }
  return 0;
}
