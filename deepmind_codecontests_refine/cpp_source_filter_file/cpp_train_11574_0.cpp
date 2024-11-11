#include <bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
const string USCAO_TAG = "nocows";
void usaco() {
  setIn(USCAO_TAG + ".in");
  setOut(USCAO_TAG + ".out");
}
template <typename... Args>
void print(Args... args) {
  ((std::cout << args << " "), ...);
}
int freq[100006][30];
int freq2[100006];
vector<string> st[100006][30];
int lst[100006][30];
vector<string> dbs, sns;
vector<int> rem[100006];
bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u');
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    char lst;
    int cnt = 0;
    for (auto x : s) {
      if (isVowel(x)) {
        cnt++;
        lst = x;
      }
    }
    freq[cnt][lst - 'a']++;
    st[cnt][lst - 'a'].emplace_back(s);
  }
  int db = 0;
  int sg = 0;
  for (int i = 1; i <= 1e5; i++) {
    for (int j = 0; j < 27; j++) {
      freq2[i] += (freq[i][j] % 2);
      int add = (freq[i][j] - (freq[i][j] % 2)) / 2;
      db += add;
      for (int k = 0; k < add * 2; k++) {
        dbs.emplace_back(st[i][j][k]);
      }
      lst[i][j] = add * 2;
      rem[i].emplace_back(j);
    }
  }
  for (int i = 1; i <= 1e5; i++) {
    if (freq2[i] != 0) {
      freq2[i] -= (freq2[i] % 2);
      sg += freq2[i] / 2;
    }
    int cc = 0;
    for (auto x : rem[i]) {
      for (int j = lst[i][x]; j < freq[i][x]; j++) {
        sns.emplace_back(st[i][x][j]);
        cc++;
      }
    }
    if (cc & 1) sns.pop_back();
  }
  cout << min(db, sg) + max(0, (db - sg) / 2) << endl;
  for (int i = 0; i < min(db, sg) * 2; i += 2) {
    cout << sns[i] << " " << dbs[i] << endl;
    cout << sns[i + 1] << " " << dbs[i + 1] << endl;
  }
  for (int i = min(db, sg) * 2, j = 0; j / 2 < (db - sg) / 2; j += 2, i += 2) {
    cout << dbs[dbs.size() - i - 1] << " " << dbs[i] << endl;
    cout << dbs[dbs.size() - i - 2] << " " << dbs[i + 1] << endl;
  }
}
