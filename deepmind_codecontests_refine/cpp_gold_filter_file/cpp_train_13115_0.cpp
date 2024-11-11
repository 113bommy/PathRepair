#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#define say(args) cout << (args) << endl
#define rep(i, a) for (int i = 0; i < a; i++)

using namespace std;

typedef struct point {
  int x;
  int y;
} Point;

string make_key(int x, int y) {
  char xx = x + '0', yy = y + '0';
  char orig[] = {xx, ',', yy};
  return string(orig, end(orig));
}

void exec(string& jfen) {
  int nums[4];
  rep(i, 4) {
    int n;
    cin >> nums[i];
  }
  Point before = { nums[1] - 1, nums[0] - 1 };
  Point next   = { nums[3] - 1, nums[2] - 1 };

  map<string, int> board;

  int x = 0, y = 0;
  int x_limit;
  for (auto c : jfen) {
    if (c == '/') {
      y += 1;
      x_limit = x;
      x = 0;
    }
    else if (c == 'b') {
      board[ make_key(x, y) ] = 1;
      x += 1;
    }
    else if (c <= '9' && c >= '1') {
      // char to int
      for (int i = 0; i < c - '0'; i++) {
        board[ make_key(x, y) ] = 0;
        x += 1;
      }
    }
  }
  int y_limit = y + 1;

  board[ make_key(before.x, before.y) ] = 0;
  board[ make_key(next.x, next.y) ]     = 1;

  for (int y = 0; y < y_limit; y++) {
    for (int x = 0; x < x_limit; x++) {
      if (board[ make_key(x, y) ] == 1) {
        cout << "b";
      } else {
        int count = 1;
        while (board[ make_key(x + 1, y)] == 0 && x < x_limit - 1) {
          count += 1;
          x += 1;
        }
        cout << count;
      }
    }
    if (y < y_limit - 1) {
      cout << "/";
    }
  }
  puts("");
}

int main() {
  string jfen;
  cin >> jfen;
  while (jfen[0] != '#' && jfen.length() != 1) {
    exec(jfen);
    cin >> jfen;
  }
}