#include <bits/stdc++.h>
using namespace std;
vector<string> splitstr(string &s) {
  vector<string> result;
  int n = s.length();
  char char_arr[n + 1];
  strcpy(char_arr, s.c_str());
  string word = "";
  for (int i = 0; i < n; i++) {
    if (char_arr[i] == 32) {
      char_arr[i] += 13;
    }
  }
  char *token = strtok(char_arr, "-");
  while (token != NULL) {
    result.push_back(token);
    token = strtok(NULL, "-");
  }
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = (0); i <= (int(n) - 1); ++i) {
    cin >> a[i];
  }
  map<int, int> make_pair;
  for (int i = (0); i <= (int(n) - 1); ++i) {
    make_pair[a[i]] = i + 1;
  }
  int m;
  cin >> m;
  int ans1 = 0, ans2 = 0;
  while (m--) {
    int temp;
    cin >> temp;
    ans1 += make_pair[temp];
    ans2 += n - make_pair[temp] + 1;
  }
  cout << ans1 << " " << ans2;
  return 0;
}
