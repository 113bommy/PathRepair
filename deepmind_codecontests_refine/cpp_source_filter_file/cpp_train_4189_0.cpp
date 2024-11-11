#include <bits/stdc++.h>
using namespace std;
vector<int> solve1(string& mask, int N) {
  vector<int> solution;
  int depth = 0;
  int height = 0;
  set<int> items;
  for (int i = 0; i < N; ++i) {
    items.insert(i + 1);
  }
  vector<int> streaks;
  int streak = 1;
  for (int i = 0; i < N - 1; ++i) {
    if (mask[i] == '<') {
      vector<int> pack;
      while (streak--) {
        int p = *items.begin();
        pack.push_back(p);
        items.erase(p);
      }
      std::reverse(pack.begin(), pack.end());
      solution.insert(solution.end(), pack.begin(), pack.end());
      streak = 1;
    } else {
      streak++;
    }
  }
  vector<int> pack;
  while (streak--) {
    int p = *items.begin();
    pack.push_back(p);
    items.erase(p);
  }
  std::reverse(pack.begin(), pack.end());
  solution.insert(solution.end(), pack.begin(), pack.end());
  return solution;
}
vector<int> solve2(string& mask, int N) {
  vector<int> solution;
  int depth = 0;
  int height = 0;
  set<int> items;
  for (int i = 0; i < N; ++i) {
    items.insert(i + 1);
  }
  vector<int> streaks;
  int streak = 1;
  for (int i = 0; i < N - 1; ++i) {
    if (mask[i] == '>') {
      vector<int> pack;
      while (streak--) {
        int p = *prev(items.end());
        pack.push_back(p);
        items.erase(p);
      }
      std::reverse(pack.begin(), pack.end());
      solution.insert(solution.end(), pack.begin(), pack.end());
      streak = 1;
    } else {
      streak++;
    }
  }
  vector<int> pack;
  while (streak--) {
    int p = *prev(items.end());
    pack.push_back(p);
    items.erase(p);
  }
  std::reverse(pack.begin(), pack.end());
  solution.insert(solution.end(), pack.begin(), pack.end());
  return solution;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int64_t N;
    string mask;
    cin >> N;
    cin >> mask;
    vector<int> s1 = solve1(mask, N);
    for (auto p : s1) {
      cout << p << ' ';
    }
    cout << endl;
    vector<int> s2 = solve2(mask, N);
    for (auto p : s2) {
      cout << p << ' ';
    }
    cout << endl;
  }
}
