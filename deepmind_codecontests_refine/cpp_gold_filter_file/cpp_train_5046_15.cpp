#include <bits/stdc++.h>
using namespace std;
int degree[1000001];
int xorarr[1000001];
queue<int> q;
vector<pair<int, int> > vec;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    degree[i] = a;
    xorarr[i] = b;
    if (a == 1) {
      q.push(i);
    }
  }
  while (q.empty() == false) {
    int a = q.front();
    q.pop();
    if (degree[a] == 0) continue;
    degree[a]--;
    int b = xorarr[a];
    vec.push_back(make_pair(a, b));
    xorarr[b] = xorarr[b] ^ a;
    degree[b]--;
    xorarr[a] = 0;
    if (degree[b] == 1) {
      q.push(b);
    }
  }
  vector<pair<int, int> >::iterator it;
  cout << vec.size() << endl;
  for (it = vec.begin(); it != vec.end(); it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
  return 0;
}
