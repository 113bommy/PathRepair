#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
int arr[24];
int transit[6][8] = {
    {13, 14, 5, 6, 17, 18, 21, 22}, {3, 4, 17, 19, 10, 9, 16, 14},
    {15, 16, 7, 8, 19, 20, 23, 24}, {1, 3, 5, 7, 9, 11, 22, 24},
    {2, 4, 6, 8, 10, 12, 23, 21},   {13, 15, 1, 2, 17, 19, 10, 9},
};
bool check_face(int f) {
  bool flag = true;
  int c = arr[4 * f];
  for (int i = 4 * f; i < 4 * (f + 1); i++)
    if (arr[i] != c) flag = false;
  return flag;
}
bool check() {
  bool flag = check_face(0);
  for (int i = 0; i < 6; i++) flag *= check_face(i);
  return flag;
}
void rotate(int face) {
  int a = arr[transit[face][0]], b = arr[transit[face][1]];
  for (int i = 0; i < 3; i++) {
    arr[transit[face][2 * i]] = arr[transit[face][2 * i + 2]];
    arr[transit[face][2 * i + 1]] = arr[transit[face][2 * i + 3]];
  }
  arr[transit[face][6]] = a;
  arr[transit[face][7]] = b;
}
void rotate(int face, int dir) {
  if (dir == -1) {
    rotate(face);
    rotate(face);
  }
  rotate(face);
}
void print() {
  for (int i = 0; i < 24; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 24; i++) cin >> arr[i];
  if (check()) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 8; j++) transit[i][j]--;
  for (int face = 0; face < 6; face++) {
    if (!check_face(face)) continue;
    rotate(face, -1);
    if (check()) {
      cout << "YES" << '\n';
      return 0;
    }
    rotate(face, 1);
    rotate(face, 1);
    if (check()) {
      cout << "YES" << '\n';
      return 0;
    }
    rotate(face, -1);
  }
  cout << "NO" << '\n';
  return 0;
}
