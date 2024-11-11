#include <bits/stdc++.h>
using namespace std;
bool mat[1000][1000] = {false};
vector<string> vec;
string word;
int suff(int size, int len, int past) {
  if (len - size < 4 || mat[size][len]) return 0;
  string ans;
  bool flg = false;
  for (int i = 0; i < size; i++) {
    ans += word[len - size + i + 1];
    if (past != size ||
        (past == size && word[len - size + i + 1] != word[len + i + 1]))
      flg = true;
  }
  if (flg) {
    mat[size][len] = true;
    bool flg2 = true;
    for (int i = 0; i < vec.size(); i++)
      if (vec[i] == ans) flg2 = false;
    if (flg2) vec.push_back(ans);
    suff(2, len - size, size);
    suff(3, len - size, size);
  }
  return 0;
}
bool Myfunction(string a, string b) { return a < b; }
int main() {
  cin >> word;
  int len = word.size() - 1;
  suff(2, len, 0);
  suff(3, len, 0);
  cout << vec.size() << endl;
  sort(vec.begin(), vec.end(), Myfunction);
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
  return 0;
}
