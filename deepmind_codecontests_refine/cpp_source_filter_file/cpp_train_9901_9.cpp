#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > mas;
int n;
void del(multiset<int> &setas, int x) {
  auto kur = setas.find(x);
  if (kur != setas.end()) setas.erase(kur);
}
multiset<int> xai, yai;
int main() {
  cin >> n;
  mas.resize(n);
  for (auto &x : mas) {
    cin >> x.first >> x.second;
  }
  long long sk = 0;
  for (int i = 0; i < n; i++) {
    sk += abs(mas[i].first - mas[(i + 1) % n].first) +
          abs(mas[i].second - mas[(i + 1) % n].second);
    xai.insert(mas[i].first);
    yai.insert(mas[i].second);
  }
  int trys = 0;
  for (int i = 0; i < n; i++) {
    int x = mas[i].first;
    int y = mas[i].second;
    del(xai, x);
    del(yai, y);
    int mnx = *xai.begin();
    int mny = *yai.begin();
    int mxx = *xai.rbegin();
    int mxy = *xai.rbegin();
    trys = max(trys, 2 * ((x - mnx) + (y - mny)));
    trys = max(trys, 2 * ((x - mnx) + (mxy - y)));
    trys = max(trys, 2 * ((mxx - x) + (y - mny)));
    trys = max(trys, 2 * ((mxx - x) + (mxy - y)));
    xai.insert(x);
    yai.insert(y);
  }
  cout << trys << " ";
  for (int i = 3; i < n; i++) {
    cout << sk << " ";
  }
  return 0;
}
