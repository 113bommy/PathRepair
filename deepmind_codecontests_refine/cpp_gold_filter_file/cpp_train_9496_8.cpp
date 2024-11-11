#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  register T sum = 0;
  register char cc = getchar();
  int sym = 1;
  while (cc != '-' && (cc > '9' || cc < '0')) cc = getchar();
  if (cc == '-') sym = -1, cc = getchar();
  sum = sum * 10 + cc - '0';
  cc = getchar();
  while (cc >= '0' && cc <= '9') sum = sum * 10 + cc - '0', cc = getchar();
  return sym * sum;
}
template <typename T>
inline T read(T &a) {
  a = read<T>();
  return a;
}
template <typename T, typename... Others>
inline void read(T &a, Others &...b) {
  a = read(a);
  read(b...);
}
int n, buck[300];
string s, ans;
bool cmp(const string &s1, const string &s2) { return s1.size() < s2.size(); }
void Get1(int n) {
  static multiset<string> st;
  static vector<string> v;
  printf("? 1 %d\n", n);
  fflush(stdout);
  for (int i = 1; i <= n * (n + 1) / 2; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    st.insert(s);
  }
  printf("? 2 %d\n", n);
  fflush(stdout);
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    st.erase(st.find(s));
  }
  for (auto i : st) v.push_back(i);
  sort(v.begin(), v.end(), cmp);
  ans[0] = v[0][0];
  for (int i = 2; i <= n; i++) {
    for (auto j : v[i - 1]) buck[j] += 1;
    for (auto j : v[i - 2]) buck[j] -= 1;
    for (int j = 'a'; j <= 'z'; j++) {
      if (buck[j]) {
        ans[i - 1] = j;
        buck[j] = 0;
        break;
      }
    }
  }
}
void Get2(int n) {
  static vector<string> v[110];
  int n1 = (n + 1) / 2;
  Get1(n1);
  printf("? 1 %d\n", n);
  for (int i = 1; i <= n * (n + 1) / 2; i++) {
    cin >> s;
    v[s.size()].push_back(s);
  }
  for (int i = 0; i < n - n1; i++) {
    for (int j = 'a'; j <= 'z'; j++) buck[j] = 0;
    for (auto j : v[n - i - 1])
      for (auto k : j) buck[k] += 1;
    for (int j = 1; j <= i + 1; j++) buck[ans[j - 1]] -= j;
    for (int j = n - i + 1; j <= n; j++) buck[ans[j - 1]] -= n - j + 1;
    for (int j = 'a'; j <= 'z'; j++)
      if (buck[j] % (i + 2) != 0) {
        ans[n - i - 1] = j;
        break;
      }
  }
}
void print() {
  cout << "! " << ans << endl;
  fflush(stdout);
}
int main() {
  cin >> n;
  ans.resize(n);
  if (n == 1) {
    printf("? 1 1\n");
    fflush(stdout);
    cin >> ans;
    print();
  } else if (n < 6) {
    Get1(n);
    print();
  } else {
    Get2(n);
    print();
  }
  return 0;
}
