#include <bits/stdc++.h>
using namespace std;
struct candy {
  int type;
  int height;
  int mass;
  candy(int _type, int _height, int _mass) {
    type = _type;
    height = _height;
    mass = _mass;
  }
};
bool compare(const candy &a, const candy &b) { return a.mass < b.mass; }
vector<candy> kitkat;
vector<candy> hersheys;
int resultado(int type, int jump) {
  int eaten = 0;
  bool found = true;
  vector<candy> auxKit = kitkat;
  vector<candy> auxHer = hersheys;
  vector<candy> p;
  while (found) {
    if (type == 0)
      p = auxKit;
    else
      p = auxHer;
    found = false;
    for (int i = 0; i < p.size(); i++) {
      if (p[i].height <= jump) {
        jump += p[i].mass;
        if (type == 0)
          auxKit.erase(auxKit.begin() + i);
        else
          auxHer.erase(auxHer.begin() + i);
        found = true;
        eaten++;
        break;
      }
    }
    if (found) {
      if (!type)
        type = 1;
      else
        type = 0;
    }
  }
  return eaten;
}
int main() {
  int n, start, t, h, m;
  cin >> n >> start;
  for (int i = 0; i < n; i++) {
    cin >> t >> h >> m;
    if (t == 0)
      kitkat.push_back(candy(t, h, m));
    else
      hersheys.push_back(candy(t, h, m));
  }
  sort(kitkat.begin(), kitkat.end(), compare);
  sort(hersheys.begin(), hersheys.end(), compare);
  cout << max(resultado(0, start), resultado(1, start)) << endl;
  return 0;
}
