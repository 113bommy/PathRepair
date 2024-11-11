#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32000000")
const int nil = -1;
using namespace std;
inline bool read(int& val) { return scanf("%d", &val) != -1; }
inline bool read(double& val) { return scanf("%lf", &val) != -1; }
inline bool read(char* val) { return scanf("%s", val) != -1; }
template <class T1, class T2>
inline bool read(T1& a, T2& b) {
  return read(a) && read(b);
}
template <class T1, class T2, class T3>
inline bool read(T1& a, T2& b, T3& c) {
  return read(a) && read(b) && read(c);
}
template <class T1, class T2, class T3, class T4>
inline bool read(T1& a, T2& b, T3& c, T4& d) {
  return read(a) && read(b) && read(c) && read(d);
}
template <class T1, class T2, class T3, class T4, class T5>
inline bool read(T1& a, T2& b, T3& c, T4& d, T5& e) {
  return read(a) && read(b) && read(c) && read(d) && read(e);
}
const int M = 31;
const int N = 211111;
map<string, int> nums;
string file[2][N];
int cnt[N];
int vis[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1, _ = (n); i <= _; ++i) {
    char str[100];
    sprintf(str, "%d", i);
    nums[str] = i;
  }
  for (int i = 0, _ = (n); i < _; ++i) {
    string name;
    int type;
    cin >> name >> type;
    type = 1 - type;
    file[type][cnt[type]++] = name;
  }
  int C[2] = {cnt[0], cnt[1]};
  cnt[0] = cnt[1] = 0;
  for (int t = 0, _ = (2); t < _; ++t)
    for (int i = 0, _ = (C[t]); i < _; ++i) {
      int val = nums[file[t][i]];
      vis[val] = 2;
      if (t == 0 && val != 0 && val <= C[0])
        vis[val] = 1;
      else if (t == 1 && val != 0 && val > C[0])
        vis[val] = 1;
      else
        file[t][cnt[t]++] = file[t][i];
    }
  for (int t = 0, _ = (2); t < _; ++t) {
    int k = 0;
    for (int i = 0, _ = (cnt[i]); i < _; ++i)
      if (nums[file[t][i]] != 0) {
        swap(file[t][i], file[t][k++]);
      }
  }
  int p = 0, q = 0;
  int sum = 0;
  for (int i = 1, _ = (n); i <= _; ++i)
    if (vis[i] == 0) sum++;
  if (sum == 0 && cnt[0] + cnt[1] != 0) {
    cout << cnt[0] + cnt[1] + 1 << endl;
    for (int i = 1, _ = (n); i <= _; ++i) {
      vis[nums[file[0][0]]] = 0;
      cout << "move " << file[0][0] << " "
           << "0" << endl;
      file[0][0] = "0";
      swap(file[0][0], file[0][cnt[0] - 1]);
      break;
    }
  } else {
    cout << cnt[0] + cnt[1] << endl;
  }
  for (int i = 1, _ = (n); i <= _; ++i)
    if (vis[i] == 0) {
      int s = i;
      while (s != 0) {
        if (s <= C[0]) {
          cout << "move " << file[0][p] << " " << s << endl;
          vis[s] = 1;
          s = nums[file[0][p++]];
        } else {
          cout << "move " << file[1][q] << " " << s << endl;
          vis[s] = 1;
          s = nums[file[1][q++]];
        }
      }
    }
  return 0;
}
