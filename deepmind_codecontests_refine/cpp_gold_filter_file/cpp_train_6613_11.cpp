#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int rows[5] = {3, 4, 5, 4, 3};
bool dp[1 << 19], seen[1 << 19];
pii int_to_pair(int c) {
  pii res = {0, 0};
  while (rows[res.first] <= c) {
    c -= rows[res.first];
    res.first++;
  }
  res.second = c;
  return res;
}
int pair_to_int(pii p) {
  int res = 0;
  for (int i = 0; i < p.first; i++) res += rows[i];
  res += p.second;
  return res;
}
pii next_coords(pii p, int dir) {
  if (dir == 0) {
    return {p.first, p.second - 1};
  } else if (dir == 1) {
    if (p.first <= 2) {
      return {p.first - 1, p.second - 1};
    } else {
      return {p.first - 1, p.second};
    }
  } else if (dir == 2) {
    if (p.first <= 2) {
      return {p.first - 1, p.second};
    } else {
      return {p.first - 1, p.second + 1};
    }
  } else if (dir == 3) {
    return {p.first, p.second + 1};
  } else if (dir == 4) {
    if (p.first >= 2) {
      return {p.first + 1, p.second};
    } else {
      return {p.first + 1, p.second + 1};
    }
  } else if (dir == 5) {
    if (p.first >= 2) {
      return {p.first + 1, p.second - 1};
    } else {
      return {p.first + 1, p.second};
    }
  }
}
void print_box(int box) {
  int b = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5 - rows[i]; j++) printf(" ");
    for (int j = 0; j < rows[i]; j++) {
      printf("%c ", ".O"[(box >> b) & 1]);
      b++;
    }
    printf("\n");
  }
}
bool getdp(int box) {
  if (box == 0) return false;
  if (seen[box]) {
    return dp[box];
  }
  seen[box] = true;
  for (int i = 0; i < 19; i++) {
    if (!(box & (1 << i))) {
      continue;
    }
    for (int dir = 0; dir < 6; dir++) {
      int boxcpy = box;
      pii curr = int_to_pair(i);
      while (true) {
        if (curr.first < 0) break;
        if (curr.first > 4) break;
        if (curr.second < 0) break;
        if (curr.second >= rows[curr.first]) break;
        if (!(boxcpy & (1 << pair_to_int(curr)))) {
          break;
        }
        boxcpy ^= (1 << pair_to_int(curr));
        if (!getdp(boxcpy)) {
          dp[box] = true;
          return true;
        }
        curr = next_coords(curr, dir);
      }
    }
  }
  return false;
}
int main() {
  int start_box = 0;
  for (int i = 0; i < 19; i++) {
    char c;
    cin >> c;
    if (c == 'O') start_box |= 1 << i;
  }
  if (getdp(start_box)) {
    cout << "Karlsson\n";
  } else {
    cout << "Lillebror\n";
  }
}
