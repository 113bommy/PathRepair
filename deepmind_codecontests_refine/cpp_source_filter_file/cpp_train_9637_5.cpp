#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << endl;
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
void run_case() {
  string test = "0000";
  string res;
  int bulls, cows, pb, pc;
  for (int i = 0; i < 4; i++) {
    pb = pc = -1;
    for (int j = 0; j < 10; j++) {
      test[i] = char(j + '0');
      print(test);
      read(bulls, cows);
      if (pb == -1) {
        pb = bulls;
        pc = cows;
        continue;
      }
      if (pb < bulls) {
        res += char(j + '0');
        int jj = j + 1;
        test[i] = char(jj + '0');
        break;
      }
      if (pb > bulls) {
        int jj = j - 1;
        res += char(jj + '0');
        test[i] = char(j + '0');
        break;
      }
    }
  }
  print(res);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  while (tt--) {
    run_case();
  }
  return 0;
}
