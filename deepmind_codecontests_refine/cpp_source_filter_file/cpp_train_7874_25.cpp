#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <typename T>
T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
vector<string> normal = {
    "no", "great!", "not bad", "don't think so", "don't touch me!", "no", "no",
    "no", "no",     "cool"};
vector<string> grumpy = {"no",      "don't even", "are you serious?",
                         "no way",  "no way",     "go die in a hole",
                         "worse",   "no",         "no",
                         "terrible"};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= 9; ++i) {
    cout << i << "\n";
    cout.flush();
    string resp;
    getline(cin, resp);
    auto it = find((normal).begin(), (normal).end(), resp);
    if (it == normal.end() || *it != resp) {
      cout << "grumpy\n";
      return 0;
    }
    normal.erase(it);
    it = find((grumpy).begin(), (grumpy).end(), resp);
    if (it == grumpy.end() || *it != resp) {
      cout << "normal\n";
      return 0;
    }
    grumpy.erase(it);
  }
  assert(0);
  return 0;
}
