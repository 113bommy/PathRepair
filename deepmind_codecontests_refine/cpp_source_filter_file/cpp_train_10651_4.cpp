#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<string, vector<int>>> V(n);
  for (int i = 0; i < n; i++) {
    int m;
    string s;
    cin >> m >> s;
    int taxi = 0, pizza = 0, girl = 0;
    V[i].first = s;
    while (m > 0) {
      string p;
      cin >> p;
      string num = "000000";
      num[0] = p[0];
      num[1] = p[1];
      num[2] = p[3];
      num[3] = p[4];
      num[4] = p[6];
      num[5] = p[7];
      if (num[0] == num[1] && num[1] == num[2] && num[2] == num[3] &&
          num[3] == num[4] && num[4] == num[5] && num[5] == num[0]) {
        taxi += 1;
      } else if (num[0] > num[1] && num[1] > num[2] && num[2] > num[3] &&
                 num[3] > num[4] && num[4] > num[5]) {
        pizza += 1;
      } else {
        girl += 1;
      }
      m--;
    }
    V[i].second.push_back(taxi);
    V[i].second.push_back(pizza);
    V[i].second.push_back(girl);
  }
  int bestTaxi = 0, bestPizza = 0, bestGirl = 0;
  for (int i = 0; i < n; i++) {
    bestTaxi = max(bestTaxi, V[i].second[0]);
    bestPizza = max(bestPizza, V[i].second[1]);
    bestGirl = max(bestGirl, V[i].second[2]);
  }
  cout << "If you want to call a taxi, you should call: ";
  int taxiC = 0;
  for (int i = 0; i < n; i++) {
    if (V[i].second[0] == bestTaxi) taxiC++;
  }
  for (int i = 0; i < n; i++) {
    if (V[i].second[0] == bestTaxi) {
      if (taxiC == 1)
        cout << V[i].first << ".";
      else {
        cout << V[i].first << ", ";
        taxiC--;
      }
    }
  }
  cout << "\nIf you want to order a pizza, you should call: ";
  int pizzaC = 0;
  for (int i = 0; i < n; i++) {
    if (V[i].second[1] == bestPizza) pizzaC++;
  }
  for (int i = 0; i < n; i++) {
    if (V[i].second[1] == bestPizza) {
      if (pizzaC == 1)
        cout << V[i].first << ".";
      else {
        cout << V[i].first << ", ";
        pizzaC--;
      }
    }
  }
  cout << "\nIf you want to go to a cafe with a wonderful girl, you should "
          "call: ";
  int girlC = 0;
  for (int i = 0; i < n; i++) {
    if (V[i].second[2] == bestGirl) girlC++;
  }
  for (int i = 0; i < n; i++) {
    if (V[i].second[2] == bestGirl) {
      if (girlC == 1)
        cout << V[i].first << ".";
      else {
        cout << V[i].first << ", ";
        girlC;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
