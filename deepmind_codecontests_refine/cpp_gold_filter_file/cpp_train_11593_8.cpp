#include <bits/stdc++.h>
using namespace std;
struct teams {
  string name;
  int compe;
  int point;
  int score;
  int misse;
};
teams t[4];
void printt(int i) {
  cout << "________________________________\n";
  cout << "team  : " << i << endl;
  cout << "name  : " << t[i].name << endl;
  cout << "compe : " << t[i].compe << endl;
  cout << "point : " << t[i].point << endl;
  cout << "score : " << t[i].score << endl;
  cout << "misse : " << t[i].misse << endl;
  cout << "________________________________\n";
}
void printall() {
  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  for (int i = 0; i < 4; i++) {
    printt(i);
  }
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int nn = 0;
int find(string n) {
  for (int i = 0; i < nn; i++) {
    if (n == t[i].name) return i;
  }
  t[nn].name = n;
  nn++;
  return nn - 1;
}
int compareteams(teams a, teams b) {
  if (a.point < b.point)
    return -1;
  else if (a.point > b.point)
    return 1;
  else if (a.score - a.misse < b.score - b.misse)
    return -1;
  else if (a.score - a.misse > b.score - b.misse)
    return 1;
  else if (a.score < b.score)
    return -1;
  else if (a.score > b.score)
    return 1;
  else if (a.name > b.name)
    return -1;
  else
    return 1;
}
int main() {
  int i;
  for (i = 1; i <= 5; i++) {
    string s1, s2;
    int a, b;
    char c;
    cin >> s1 >> s2 >> a >> c >> b;
    int k1 = find(s1), k2 = find(s2);
    if (a > b)
      t[k1].point += 3;
    else if (a < b)
      t[k2].point += 3;
    else {
      t[k1].point += 1;
      t[k2].point += 1;
    }
    t[k1].compe += 1;
    t[k2].compe += 1;
    t[k1].score += a;
    t[k1].misse += b;
    t[k2].score += b;
    t[k2].misse += a;
  }
  int be = -1;
  be = find("BERLAND");
  int ju = 0;
  for (i = 0; i < 4; i++) {
    if (t[be].point + 3 < t[i].point) ju++;
  }
  if (ju >= 2) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int ot = -1;
  for (i = 0; i < 4; i++) {
    if (i != be && t[i].compe == 2) ot = i;
  }
  for (int d = 1; d <= 60; d++) {
    for (int k = 0; k <= 60; k++) {
      i = k + d;
      t[be].point += 3;
      t[be].score += i;
      t[be].misse += k;
      t[ot].misse += i;
      t[ot].score += k;
      int rank = 1;
      for (int j = 0; j < 4; j++) {
        if (j != be && compareteams(t[be], t[j]) == -1) {
          rank++;
        }
      }
      if (rank <= 2) {
        cout << i << ":" << k << endl;
        return 0;
      }
      t[be].point -= 3;
      t[be].score -= i;
      t[be].misse -= k;
      t[ot].misse -= i;
      t[ot].score -= k;
    }
  }
  return 0;
}
