#include <bits/stdc++.h>
using namespace std;
int games;
int indexof1[100001];
int indexof2[100001];
int score1[100001];
int score2[100001];
vector<int> scratch[100001];
pair<vector<int>, vector<vector<int> > > options(vector<int> scores) {
  for (int i = 0; i <= scores.size(); i++) {
    score1[i] = score2[i] = 0;
    indexof1[i] = indexof2[i] = -1;
  }
  for (int i = 0; i < scores.size(); i++) {
    if (i != 0) {
      score1[i] = score1[i - 1];
      score2[i] = score2[i - 1];
    }
    if (scores[i] == 0) {
      score1[i]++;
    } else {
      score2[i]++;
    }
  }
  for (int i = 0; i < scores.size(); i++) {
    if (indexof1[score1[i]] == -1) {
      indexof1[score1[i]] = i;
    }
    if (indexof2[score2[i]] == -1) {
      indexof2[score2[i]] = i;
    }
  }
  indexof1[0] = -1;
  indexof2[0] = -1;
  vector<int> ret;
  vector<vector<int> > retlist;
  for (int i = 1; i <= scores.size(); i++) {
    int s1 = 0, s2 = 0;
    vector<int> val;
    while (true) {
      int i1 = (1 << 30), i2 = (1 << 30);
      if (s1 + i <= scores.size() && indexof1[s1 + i] != -1) {
        i1 = indexof1[s1 + i];
      }
      if (s2 + i <= scores.size() && indexof2[s2 + i] != -1) {
        i2 = indexof2[s2 + i];
      }
      if (i1 == (1 << 30) && i2 == (1 << 30)) {
        if (s1 + s2 == scores.size()) {
          ret.push_back(i);
          retlist.push_back(val);
        }
        break;
      }
      if (i1 < i2) {
        val.push_back(0);
        s1 += i;
        s2 = score2[i1];
      } else {
        val.push_back(1);
        s2 += i;
        s1 = score1[i2];
      }
    }
  }
  return make_pair(ret, retlist);
}
vector<int> gamelist;
pair<int, int> output[100000];
int outputs;
int main() {
  int games;
  cin >> games;
  for (int i = 0; i < games; i++) {
    int a;
    cin >> a;
    a--;
    gamelist.push_back(a);
  }
  pair<vector<int>, vector<vector<int> > > result = options(gamelist);
  for (int i = 0; i < result.first.size(); i++) {
    int score1 = 0;
    for (int j = 0; j < result.second[i].size(); j++) {
      if (result.second[i][j] == 0) score1++;
    }
    if (score1 > result.second[i].size() / 2) {
      if (result.second[i][result.second[i].size() - 1] == 0) {
        output[outputs++] = make_pair(score1, result.first[i]);
      }
    }
    if (score1 < (result.second[i].size() + 1) / 2) {
      if (result.second[i][result.second[i].size() - 1] == 1) {
        output[outputs++] =
            make_pair(result.second[i].size() - score1, result.first[i]);
      }
    }
  }
  sort(output, output + outputs);
  cout << outputs << "\n";
  for (int i = 0; i < outputs; i++) {
    cout << output[i].first << " " << output[i].second << "\n";
  }
}
