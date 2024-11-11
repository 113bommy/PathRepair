#include <bits/stdc++.h>
using namespace std;
int N;
string S[100001];
int cnt[26];
int from[26];
int find(int ind, char C) {
  for (int i = 0; i < S[ind].length(); i++)
    if (S[ind][i] == C) return i;
  return -1;
}
void merge(int I, int J, char C) {
  int indI = find(I, C);
  int indJ = find(J, C);
  int lenI = S[I].length() - indI;
  int lenJ = S[J].length() - indJ;
  int L = min(lenI, lenJ);
  if (max(indI, indJ) > 0 || S[I].substr(indI, L) != S[J].substr(indJ, L)) {
    cout << "NO" << '\n';
    exit(0);
  }
  string s;
  if (indI > indJ) {
    s = S[I];
    if (indJ + L < (int)S[J].length())
      s += S[J].substr(indJ + L, (int)S[J].length() - (indJ + L));
  } else {
    s = S[J];
    if (indI + L < (int)S[I].length())
      s += S[I].substr(indI + L, (int)S[I].length() - (indI + L));
  }
  S[J] = s;
  S[I] = "!";
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    for (int j = 0; j < 26; j++) cnt[j] = 0;
    for (int j = 0; j < S[i].length(); j++) cnt[S[i][j] - 'a']++;
    for (int j = 0; j < 26; j++)
      if (cnt[j] > 1) {
        cout << "NO" << '\n';
        return 0;
      }
  }
  for (int i = 0; i < 26; i++) from[i] = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S[i].length(); j++) {
      if (from[S[i][j] - 'a'] == -1)
        from[S[i][j] - 'a'] = i;
      else if (from[S[i][j] - 'a'] != i) {
        merge(from[S[i][j] - 'a'], i, S[i][j]);
        int temp = from[S[i][j] - 'a'];
        for (int k = 0; k < 26; k++)
          if (from[k] == temp) from[k] = i;
      }
    }
  }
  vector<string> v;
  for (int i = 0; i < N; i++)
    if (S[i] != "!") v.push_back(S[i]);
  sort(v.begin(), v.end());
  string ans = "";
  for (auto s : v) ans += s;
  for (int i = 0; i < 26; i++) cnt[i] = 0;
  for (int i = 0; i < ans.length(); i++) cnt[ans[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (cnt[i] > 1) {
      cout << "NO" << '\n';
      return 0;
    }
  cout << ans << '\n';
  return 0;
}
