#include <bits/stdc++.h>
using namespace std;
const int Maxn = 50 + 10;
int n;
struct tim {
  int scr, goal, sub;
  string name;
} arr[Maxn];
vector<string> ans;
bool moq(tim a, tim b) {
  if (a.scr < b.scr) return true;
  if (a.scr > b.scr) return false;
  if (a.sub < b.sub) return true;
  if (a.sub > b.sub) return false;
  if (a.goal < b.goal) return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].name;
  for (int k = 0; k < n * (n - 1) / 2; k++) {
    string s1, s2, s, sp;
    cin >> s >> sp;
    int j = 0;
    while (s[j] != '-') {
      s1 += s[j];
      j++;
    }
    j++;
    while (j < s.size()) {
      s2 += s[j];
      j++;
    }
    int g1 = 0, g2 = 0;
    j = 0;
    while (sp[j] != ':') {
      g1 *= 10;
      g1 += sp[j] - '0';
      j++;
    }
    j++;
    while (j < sp.size()) {
      g2 *= 10;
      g2 += sp[j] - '0';
      j++;
    }
    for (int i = 0; i < n; i++) {
      if (arr[i].name == s1) {
        arr[i].goal += g1;
        arr[i].sub += g1 - g2;
        if (g1 > g2)
          arr[i].scr += 3;
        else {
          if (g1 == g2) arr[i].scr++;
        }
      }
      if (arr[i].name == s2) {
        arr[i].goal += g2;
        arr[i].sub += g2 - g1;
        if (g2 > g1)
          arr[i].scr += 3;
        else {
          if (g1 == g2) arr[i].scr++;
        }
      }
    }
  }
  sort(arr, arr + n, moq);
  for (int i = n / 2; i < n; i++) ans.push_back(arr[i].name);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
