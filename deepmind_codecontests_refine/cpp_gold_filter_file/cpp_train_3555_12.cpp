#include <bits/stdc++.h>
using namespace std;
class move {
 public:
  int first;
  int second;
  int dist;
};
int main() {
  int n;
  cin >> n;
  pair<int, int> initial[n];
  int positions[n];
  for (int i = 0; i < n; i++) {
    int position;
    cin >> position;
    initial[i] = make_pair(position, i);
  }
  for (int i = 0; i < n; i++) {
    cin >> positions[i];
  }
  sort(initial, initial + n);
  sort(positions, positions + n);
  if (n == 1) {
    if (positions[0] == initial[0].first) {
      cout << "YES\n0";
    } else {
      cout << "NO";
    }
    return 0;
  }
  int move_right = 0;
  int move_left = 1;
  bool possible = true;
  vector<pair<pair<int, int>, int> > solution;
  while (move_right < n) {
    if (initial[move_right].first < positions[move_right]) {
      while (initial[move_left].first <= positions[move_left]) {
        move_left++;
        if (move_left >= n) {
          possible = false;
          break;
        }
      }
      if (possible == false) break;
      int dist = min(positions[move_right] - initial[move_right].first,
                     initial[move_left].first - positions[move_left]);
      initial[move_right].first += dist;
      initial[move_left].first -= dist;
      solution.push_back(make_pair(
          pair<int, int>(initial[move_right].second, initial[move_left].second),
          dist));
    } else if (initial[move_right].first > positions[move_right]) {
      possible = false;
      break;
    } else {
      move_right++;
    }
  }
  if (possible) {
    cout << "YES\n";
    cout << solution.size() << endl;
    for (auto s : solution) {
      cout << s.first.first + 1 << ' ' << s.first.second + 1 << ' ' << s.second
           << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
