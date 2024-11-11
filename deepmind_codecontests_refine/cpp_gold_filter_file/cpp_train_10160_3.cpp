#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, m, k, t;
  cin >> n >> m >> k >> t;
  long int a, b;
  vector<pair<long int, long int>> obs;
  for (long int i = 0; i < k; i++) {
    cin >> a >> b;
    obs.push_back({a, b});
  }
  int flag = 0, co = 0;
  for (long int i = 0; i < t; i++) {
    flag = 0, co = 0;
    cin >> a >> b;
    for (long int j = 0; j < obs.size(); j++) {
      if (obs[j].first < a)
        co++;
      else if (obs[j].first == a && obs[j].second < b)
        co++;
      else if (obs[j].first == a && obs[j].second == b)
        flag = 1;
    }
    long int totalco = (m * (a - 1) + b - co) % 3;
    if (flag == 1)
      cout << "Waste" << endl;
    else if (totalco == 1)
      cout << "Carrots" << endl;
    else if (totalco == 2)
      cout << "Kiwis" << endl;
    else
      cout << "Grapes" << endl;
  }
}
