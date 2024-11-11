#include <bits/stdc++.h>
using namespace std;
bool myComp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return (abs(a.first) + abs(a.second)) <= (abs(b.first) + abs(b.second));
}
int32_t main() {
  long long n;
  cin >> n;
  long long ans = 0;
  vector<pair<long long, long long>> bomb;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    bomb.push_back({x, y});
    if (x != 0 && y != 0)
      ans += 6;
    else if (x == 0 && y == 0)
      ans += 1;
    else if (x || y)
      ans += 4;
  }
  cout << ans << "\n";
  sort(bomb.begin(), bomb.end(), myComp);
  for (auto p : bomb) {
    long long cx = p.first, cy = p.second;
    if (cx < 0 && cy == 0) {
      cout << "1 " << abs(cx) << " L"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " R"
           << "\n";
    } else if (cx < 0 && cy < 0) {
      cout << "1 " << abs(cx) << " L"
           << "\n";
      cout << "1 " << abs(cy) << " D"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " R"
           << "\n";
      cout << "1 " << abs(cy) << " U"
           << "\n";
    } else if (cx < 0 && cy > 0) {
      cout << "1 " << abs(cx) << " L"
           << "\n";
      cout << "1 " << abs(cy) << " U"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " R"
           << "\n";
      cout << "1 " << abs(cy) << " D"
           << "\n";
    } else if (cx > 0 && cy == 0) {
      cout << "1 " << abs(cx) << " R"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " L"
           << "\n";
    } else if (cx > 0 && cy < 0) {
      cout << "1 " << abs(cx) << " R"
           << "\n";
      cout << "1 " << abs(cy) << " D"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " L"
           << "\n";
      cout << "1 " << abs(cy) << " U"
           << "\n";
    } else if (cx > 0 && cy > 0) {
      cout << "1 " << abs(cx) << " R"
           << "\n";
      cout << "1 " << abs(cy) << " U"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cx) << " L"
           << "\n";
      cout << "1 " << abs(cy) << " D"
           << "\n";
    } else if (cx == 0 && cy > 0) {
      cout << "1 " << abs(cy) << " U"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cy) << " D"
           << "\n";
    } else if (cx == 0 && cy < 0) {
      cout << "1 " << abs(cy) << " D"
           << "\n";
      cout << 2 << '\n';
      cout << "1 " << abs(cy) << " R"
           << "\n";
    }
    cout << 3 << "\n";
  }
}
