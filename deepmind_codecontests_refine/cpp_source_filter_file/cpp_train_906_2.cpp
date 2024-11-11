#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  vector<int> awesome;
  int legit = 0;
  int legit2 = 0;
  int store = 0;
  int cup1 = 0;
  int cup2 = 0;
  if (a == 1) {
    cout << "Exemplary pages.";
    return 0;
  }
  if (a == 2) {
    int b, c;
    cin >> b >> c;
    if (b > c) {
      cup1 = 1;
      cup2 = 2;
    } else if (b < c) {
      cup1 = 2;
      cup2 = 1;
    }
    if (b > c) {
      store = c;
      c = b;
      b = store;
    }
    if (b == c) {
      cout << "Exemplary pages." << endl;
      return 0;
    }
    if ((b + c) % 2 == 0) {
      cout << c - (b + c) / 2 << " ml. from cup #" << cup1 << " to cup #"
           << cup2 << "." << endl;
      return 0;
    } else {
      cout << "Unrecoverable configuration.";
      return 0;
    }
  }
  map<int, int> cooleo;
  vector<int> remaining;
  map<int, int> isit;
  for (int g = 0; g < a; g++) {
    int b;
    cin >> b;
    awesome.push_back(b);
    cooleo[b] += 1;
  }
  for (int g = 0; g < awesome.size(); g++) {
    if (cooleo[awesome[g]] != 0 && isit[awesome[g]] == 0) {
      remaining.push_back(awesome[g]);
      isit[awesome[g]] = 1;
    }
  }
  if (remaining.size() == 3) {
    sort(remaining.begin(), remaining.end());
    if (remaining[0] + remaining[2] == 2 * remaining[1] &&
        cooleo[remaining[0]] == 1 && cooleo[remaining[2]] == 1 &&
        cooleo[remaining[1]] == a - 2) {
      for (int t = 0; t < awesome.size(); t++) {
        if (awesome[t] == remaining[0]) {
          legit = t + 1;
        }
        if (awesome[t] == remaining[2]) {
          legit2 = t + 1;
        }
      }
      cout << remaining[1] - remaining[0] << " ml. from cup #" << legit
           << " to cup #" << legit2 << "." << endl;
    } else {
      cout << "Unrecoverable configuration.";
    }
  } else if (remaining.size() == 1) {
    cout << "Exemplary pages.";
  } else {
    cout << "Unrecoverable configuration.";
  }
}
