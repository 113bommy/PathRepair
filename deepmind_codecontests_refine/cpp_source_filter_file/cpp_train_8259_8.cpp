#include <bits/stdc++.h>
using namespace std;
const char al[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                      'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                      'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<vector<pair<int, int> > > my;
int counter = 0;
vector<bool> check;
vector<bool> mycheck;
map<int, int> cc;
bool flag = false;
void dfs(int id, bool sost) {
  if (sost == true) {
    flag = true;
    counter++;
    cc[id] = 1;
  } else
    cc[id] = 0;
  mycheck[id] = true;
  for (int i = 0; i < my[id].size(); i++) {
    int temp = my[id][i].first;
    if (!mycheck[temp]) {
      dfs(temp, my[id][i].second);
    }
  }
}
int get(map<int, int> o) {
  int ans = 0;
  for (map<int, int>::iterator i = o.begin(); i != o.end(); i++) {
    ans += (*i).second;
  }
  return ans;
}
vector<int> st;
int maxcounter = 100000;
void dfs3(int id, int num) {
  if (num < maxcounter) {
    maxcounter = num;
    st.clear();
    st.push_back(id);
  } else if (num == maxcounter)
    st.push_back(id);
  check[id] = true;
  for (int i = 0; i < my[id].size(); i++) {
    int temp = my[id][i].first;
    int sost = my[id][i].second;
    if (!check[temp]) {
      int tempnum;
      if (sost == true)
        tempnum = num - 1;
      else
        tempnum = num + 1;
      dfs3(temp, tempnum);
    }
  }
}
int main() {
  int n, k;
  cin >> n;
  my.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    my[x].push_back(make_pair(y, false));
    my[y].push_back(make_pair(x, true));
  }
  check.resize(n + 1, false);
  mycheck.resize(n + 1, false);
  int maxi = 0;
  dfs(1, false);
  counter = get(cc);
  dfs3(1, counter);
  cout << maxcounter << endl;
  sort(st.begin(), st.end());
  for (int i = 0; i < st.size(); i++) cout << st[i] << " ";
}
