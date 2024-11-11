#include <bits/stdc++.h>
using namespace std;
pair<int, int> changePos(char c, pair<int, int> vec) {
  if (c == 'U') vec.second++;
  if (c == 'D') vec.second--;
  if (c == 'L') vec.first--;
  if (c == 'R') vec.first++;
  return vec;
}
int main() {
  pair<int, int> f;
  string s;
  cin >> f.first >> f.second;
  cin >> s;
  if (f == make_pair(0, 0)) {
    cout << "YES" << endl;
    return 0;
  }
  pair<int, int> vec = make_pair(0, 0), vec2 = make_pair(0, 0), vec3;
  for (__typeof(((int)((s).size())) - 1) i = (0);
       i <= (((int)((s).size())) - 1); i++)
    vec = changePos(s[i], vec);
  s = "0" + s;
  bool ans = false;
  if (vec == make_pair(0, 0)) {
    for (__typeof(((int)((s).size())) - 1) i = (0);
         i <= (((int)((s).size())) - 1); i++) {
      vec2 = changePos(s[i], vec2);
      vec3 = make_pair(f.first - vec2.first, f.second - vec2.second);
      if (vec3 == make_pair(0, 0)) ans = true;
    }
  } else if (vec.first == 0) {
    for (__typeof(((int)((s).size())) - 1) i = (0);
         i <= (((int)((s).size())) - 1); i++) {
      vec2 = changePos(s[i], vec2);
      vec3 = make_pair(f.first - vec2.first, f.second - vec2.second);
      if ((vec3.first == 0) && (vec3.second % vec.second == 0))
        if (vec3.second / vec.second >= 0) {
          ans = true;
        }
    }
  } else if (vec.second == 0)
    for (__typeof(((int)((s).size())) - 1) i = (0);
         i <= (((int)((s).size())) - 1); i++) {
      vec2 = changePos(s[i], vec2);
      vec3 = make_pair(f.first - vec2.first, f.second - vec2.second);
      if ((vec3.second == 0) && (vec3.first % vec.first == 0))
        if (vec3.first / vec.first >= 0) {
          ans = true;
        }
    }
  else if (vec.first != 0 && vec.second != 0)
    for (__typeof(((int)((s).size())) - 1) i = (0);
         i <= (((int)((s).size())) - 1); i++) {
      vec2 = changePos(s[i], vec2);
      vec3 = make_pair(f.first - vec2.first, f.second - vec2.second);
      if ((vec3.first % vec.first == 0) && (vec3.second % vec.second == 0))
        if (vec3.first / vec.first == vec3.second / vec.second)
          if (vec3.first / vec.first >= 0) {
            ans = true;
          }
    }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
