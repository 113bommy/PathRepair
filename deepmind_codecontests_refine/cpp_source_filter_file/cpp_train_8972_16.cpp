#include <bits/stdc++.h>
using namespace std;
set<pair<long long, int> > cima, baixo, esq, dir;
int main() {
  int N;
  long long area;
  int sig;
  cin >> N;
  for (int i = 3; i <= N; i++) {
    cout << "1 1 2 " << i << "\n";
    cout.flush();
    cin >> area;
    cout << "2 1 2 " << i << "\n";
    cout.flush();
    cin >> sig;
    if (sig == 1) {
      cima.insert({area, i});
    } else {
      baixo.insert({area, i});
    }
  }
  vector<int> ans;
  ans.push_back(2);
  if (cima.size()) {
    auto it = cima.end();
    it--;
    int maximo = it->second;
    cima.erase(it);
    for (auto p : cima) {
      cout << "2 1 " << maximo << " " << p.second << "\n";
      cout.flush();
      cin >> sig;
      if (sig == 1)
        esq.insert(p);
      else
        dir.insert(p);
    }
    for (auto it = dir.begin(); it != dir.end(); it++)
      ans.push_back(it->second);
    ans.push_back(maximo);
    for (auto it = esq.rbegin(); it != esq.rend(); it++)
      ans.push_back(it->second);
  }
  ans.push_back(1);
  esq.clear();
  dir.clear();
  if (baixo.size()) {
    auto it = baixo.end();
    it--;
    int maximo = it->second;
    baixo.erase(it);
    for (auto p : baixo) {
      cout << "2 1 " << maximo << " " << p.second << "\n";
      cout.flush();
      cin >> sig;
      if (sig == 1)
        esq.insert(p);
      else
        dir.insert(p);
    }
    for (auto it = dir.begin(); it != dir.end(); it++)
      ans.push_back(it->second);
    ans.push_back(maximo);
    for (auto it = esq.rbegin(); it != esq.rend(); it++)
      ans.push_back(it->second);
  }
  cout << "0 ";
  for (auto v : ans) cout << v << " ";
  cout.flush();
  return 0;
}
