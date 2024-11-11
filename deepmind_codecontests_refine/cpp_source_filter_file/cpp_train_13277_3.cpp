#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32000000")
using namespace std;
#pragma comment(linker, "/STACK:56777216")
void Out(const vector<int> &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
std::vector<std::string> &split(const std::string &s, char delim,
                                std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> m;
  m.push_back(a[0]);
  for (int i = 1; i < a.size(); ++i) {
    m.push_back(min(m.back() + 1, a[i]));
  }
  cout << m.back() + 1 << endl;
  return 0;
}
