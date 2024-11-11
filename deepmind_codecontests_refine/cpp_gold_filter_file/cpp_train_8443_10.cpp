#include <bits/stdc++.h>
using namespace std;
struct Str {
  int speed;
  int ram;
  int hdd;
  int cost;
};
int main(int argc, char *argv[]) {
  int n;
  vector<Str> V;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    Str str;
    cin >> t;
    str.speed = t;
    cin >> t;
    str.ram = t;
    cin >> t;
    str.hdd = t;
    cin >> t;
    str.cost = t;
    V.push_back(str);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (V[i].speed < V[j].speed && V[i].ram < V[j].ram && V[i].hdd < V[j].hdd)
        V[i].cost = 1001;
    }
  }
  int Min = V[0].cost;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (V[i].cost < Min) {
      Min = V[i].cost;
      index = i;
    }
  }
  cout << index + 1;
  return EXIT_SUCCESS;
}
