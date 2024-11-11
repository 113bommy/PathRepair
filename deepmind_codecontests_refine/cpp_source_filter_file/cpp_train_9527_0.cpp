#include <bits/stdc++.h>
using namespace std;
vector<int> tokenize_str(const string& str, const string& delims) {
  using namespace std;
  string::size_type lastPos = str.find_first_not_of(delims, 0);
  string::size_type pos = str.find_first_of(delims, lastPos);
  vector<int> tokens;
  while (string::npos != pos || string::npos != lastPos) {
    string temp = str.substr(lastPos, pos - lastPos);
    int t = atoi(temp.c_str());
    tokens.push_back(t);
    lastPos = str.find_first_not_of(delims, pos);
    pos = str.find_first_of(delims, lastPos);
  }
  return tokens;
}
char arr[11][11][11];
int k, n, m;
int x, y;
struct node {
  int x, y, z;
};
int main() {
  string t;
  getline(cin, t);
  vector<int> tt = tokenize_str(t, " ");
  k = tt[0];
  n = tt[1];
  m = tt[2];
  int l = n;
  int r = 1;
  string s;
  for (int i = 0; i < k; i++) {
    getline(cin, s);
    for (int j = 0; j < n; j++) {
      getline(cin, s);
      for (int a = 0; a < m; a++) {
        arr[i][j][a] = s[a];
      }
    }
  }
  getline(cin, s);
  getline(cin, s);
  vector<int> ss = tokenize_str(s, " ");
  x = ss[0] - 1;
  y = ss[1] - 1;
  int result = 0;
  result++;
  list<node> qu;
  node first;
  first.x = 0;
  first.y = x;
  first.z = y;
  qu.push_back(first);
  arr[0][x][y] = 'm';
  while (!qu.empty()) {
    node no = qu.front();
    qu.pop_front();
    if (((no.z + 1) < m) && arr[no.x][no.y][no.z + 1] == '.') {
      node nn;
      nn.x = no.x;
      nn.y = no.y;
      nn.z = no.z + 1;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
    if (((no.z - 1) >= 0) && arr[no.x][no.y][no.z + 1] == '.') {
      node nn;
      nn.x = no.x;
      nn.y = no.y;
      nn.z = no.z - 1;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
    if (((no.y + 1) < n) && arr[no.x][no.y + 1][no.z] == '.') {
      node nn;
      nn.x = no.x;
      nn.y = no.y + 1;
      nn.z = no.z;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
    if (((no.y - 1) >= 0) && arr[no.x][no.y - 1][no.z] == '.') {
      node nn;
      nn.x = no.x;
      nn.y = no.y - 1;
      nn.z = no.z;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
    if (((no.x + 1) < k) && arr[no.x + 1][no.y][no.z] == '.') {
      node nn;
      nn.x = no.x + 1;
      nn.y = no.y;
      nn.z = no.z;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
    if (((no.x - 1) >= 0) && arr[no.x - 1][no.y][no.z] == '.') {
      node nn;
      nn.x = no.x - 1;
      nn.y = no.y;
      nn.z = no.z;
      qu.push_back(nn);
      arr[nn.x][nn.y][nn.z] = 'm';
      result++;
    }
  }
  cout << result;
  return 0;
}
