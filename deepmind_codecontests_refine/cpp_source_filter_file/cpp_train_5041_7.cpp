#include <bits/stdc++.h>
using namespace std;
deque<int> que[30];
string str;
int main() {
  cin >> str;
  int n = str.length();
  vector<int> counter;
  counter.push_back(0);
  for (int i = 0; i < n; i++) {
    que[str[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    vector<int> pos;
    for (int j = 0; j < 26; j++) {
      while (!que[j].empty() && que[j].front() < i) que[j].pop_front();
      if (!que[j].empty()) pos.push_back(que[j].front());
    }
    sort(pos.begin(), pos.end());
    pos.push_back(n);
    for (int j = 1; j < pos.size(); j++) {
      int t = pos[j] - pos[j - 1];
      if (counter.size() <= j)
        counter.push_back(t);
      else
        counter[j] += t;
    }
  }
  cout << counter.size() - 1 << endl;
  for (int i = 1; i < counter.size(); i++) {
    cout << counter[i] << endl;
  }
  return 0;
}
