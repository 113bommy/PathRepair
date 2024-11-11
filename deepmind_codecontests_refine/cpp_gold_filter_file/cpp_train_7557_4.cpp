#include <bits/stdc++.h>
using namespace std;
long long n, k;
set<char> good;
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  string goods, pattern, query, woast;
  int split = -1;
  cin >> goods >> pattern >> n;
  bool ast = false;
  for (int i = 0; i < pattern.length(); i++) {
    if (pattern[i] == '*') {
      split = i;
      ast = true;
      woast = pattern;
      woast.erase(i, 1);
      break;
    }
  }
  for (int i = 0; i < goods.length(); i++) {
    good.insert(goods[i]);
  }
  bool eq;
  for (int i = 0; i < n; i++) {
    cin >> query;
    eq = true;
    if (pattern.length() != query.length() && split == -1) {
      cout << "NO" << endl;
      continue;
    }
    if (pattern.length() - 1 > query.length() && split != -1) {
      cout << "NO" << endl;
      continue;
    }
    if (!(pattern.length() <= query.length() ||
          pattern.length() - 1 <= query.length() && split != -1)) {
      cout << "NO" << endl;
      continue;
    }
    if (pattern.length() == query.length() && split == -1) {
      for (int j = 0; j < pattern.length(); j++) {
        if (pattern[j] == query[j]) {
          continue;
        } else if (pattern[j] == '?' && good.find(query[j]) != good.end()) {
          continue;
        } else {
          eq = false;
          break;
        }
      }
    } else {
      for (int j = 0; j < split; j++) {
        if (pattern[j] == query[j]) {
          continue;
        } else if (pattern[j] == '?' && good.find(query[j]) != good.end()) {
          continue;
        } else {
          eq = false;
          break;
        }
      }
      for (int j = 0; j < pattern.length() - split - 1; j++) {
        if (pattern[pattern.length() - j - 1] ==
            query[query.length() - j - 1]) {
          continue;
        } else if (pattern[pattern.length() - j - 1] == '?' &&
                   good.find(query[query.length() - j - 1]) != good.end()) {
          continue;
        } else {
          eq = false;
          break;
        }
      }
      for (int j = split; j < query.length() - (pattern.length() - split - 1);
           j++) {
        if (good.find(query[j]) != good.end()) {
          eq = false;
          break;
        }
      }
    }
    if (eq) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
