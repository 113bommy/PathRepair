#include <bits/stdc++.h>
using namespace std;
vector<int> ones, evens, odds;
int prime(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    if (input % 2 == 0)
      evens.push_back(input);
    else if (input == 1)
      ones.push_back(input);
    else if (input % 2 == 1)
      odds.push_back(input);
  }
  if (ones.size() > 1) {
    for (auto x : evens) {
      if (prime(x + 1)) {
        cout << ones.size() + 1 << endl;
        cout << x << " ";
        for (auto y : ones) {
          cout << y << " ";
        }
        return 0;
      }
    }
    cout << ones.size() << endl;
    for (auto y : ones) {
      cout << y << " ";
    }
    return 0;
  } else if (ones.size() == 1) {
    for (auto x : evens) {
      for (auto y : odds) {
        if (prime(x + y)) {
          cout << 3 << endl;
          cout << x << " " << y;
          return 0;
        }
      }
    }
    for (auto x : evens) {
      if (prime(x + 1)) {
        cout << 2 << endl;
        cout << x << " " << 1;
        return 0;
      }
    }
    cout << 1 << endl;
    cout << 1;
  } else {
    if (odds.size() == 0) {
      cout << 1 << endl;
      cout << evens[0];
    } else if (evens.size() == 0) {
      cout << 1 << endl;
      cout << odds[0];
    } else {
      for (auto x : evens) {
        for (auto y : odds) {
          if (prime(x + y)) {
            cout << 2 << endl;
            cout << x << " " << y;
            return 0;
          }
        }
      }
      cout << 1 << endl;
      cout << evens[0];
    }
  }
  return 0;
}
