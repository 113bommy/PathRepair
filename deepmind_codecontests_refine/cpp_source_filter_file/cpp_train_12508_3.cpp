#include <bits/stdc++.h>
using namespace std;
struct student {
  int ab, in;
  student(int a, int i) {
    ab = a;
    in = i;
  }
};
bool operator<(student a, student b) { return a.ab > b.ab; }
set<student> _set;
int l_routes[200 * 1000 + 100];
int r_routes[200 * 1000 + 100];
int commands[200 * 1000 + 100];
int mas[200 * 1000 + 100];
int main() {
  int k, n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mas[i] = a;
    r_routes[i] = i - 1;
    l_routes[i] = i + 1;
    _set.insert(student(a, i));
  }
  int command = 1;
  while (!_set.empty()) {
    auto x = (*_set.begin());
    _set.erase(x);
    commands[x.in] = command;
    int left = l_routes[x.in];
    int right = r_routes[x.in];
    int l_steps = 0;
    while (l_steps < k && left >= 0) {
      commands[left] = command;
      _set.erase(student(mas[left], left));
      left = l_routes[left];
      l_steps++;
    }
    int r_steps = 0;
    while (r_steps < k && right < n) {
      commands[right] = command;
      _set.erase(student(mas[right], right));
      right = r_routes[right];
      r_steps++;
    }
    if (left != -1) {
      r_routes[left] = right;
    }
    if (right < n) {
      l_routes[right] = left;
    }
    command = (command == 1) ? (2) : (1);
  }
  for (int i = 0; i < n; i++) {
    cout << commands[i];
  }
}
