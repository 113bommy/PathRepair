#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}
struct category {
  string name;
  string cate;
};
int main() {
  map<string, int> score;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int scr;
    cin >> name >> scr;
    score[name] = max(score[name], scr);
  }
  vector<pair<string, int> > sorted;
  for (map<string, int>::iterator i = score.begin(); i != score.end(); i++)
    sorted.push_back(make_pair(i->first, i->second));
  sort(sorted.begin(), sorted.end(), cmp);
  int playernum = sorted.size();
  category ans[1001];
  int curscore = -1, betternum = -1;
  for (int i = playernum - 1; i >= 0; i--) {
    if (sorted[i].second != curscore) {
      curscore = sorted[i].second;
      betternum = playernum - i - 1;
    }
    ans[i].name = sorted[i].first;
    double ratio = (double)((double)betternum / (double)playernum);
    if (ratio > 0.5) {
      ans[i].cate = "noob";
      continue;
    }
    if (ratio > 0.2) {
      ans[i].cate = "random";
      continue;
    }
    if (ratio > 0.1) {
      ans[i].cate = "average";
      continue;
    }
    if (ratio > 0.01) {
      ans[i].cate = "hardcore";
      continue;
    }
    ans[i].cate = "pro";
  }
  cout << playernum << endl;
  for (int i = 0; i < playernum; i++)
    cout << ans[i].name << " " << ans[i].cate << endl;
  return 0;
}
