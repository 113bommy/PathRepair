#include <bits/stdc++.h>
using namespace std;
pair<long long int, int> trains[3 * 100005];
bool used[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, h, k;
  cin >> n >> h >> m >> k;
  for (int i = 0; i < n; i++) {
    int temp;
    long long int val;
    cin >> temp >> val;
    trains[3 * i].second = i;
    trains[3 * i + 1].second = i;
    trains[3 * i + 2].second = i;
    val %= m / 2;
    trains[3 * i].first = val;
    trains[3 * i + 1].first = val - (m / 2);
    trains[3 * i + 2].first = val + (m / 2);
  }
  sort(trains, trains + 3 * n);
  int debut = 0;
  while (trains[debut].first < -k) debut++;
  int fin = debut;
  int best = INT_MAX;
  set<int> compte;
  for (; trains[debut].first < (m / 2) - k; debut++) {
    while (trains[fin].first - trains[debut].first < k) {
      compte.insert(trains[fin].second);
      fin++;
    }
    compte.erase(trains[debut].second);
    best = min<int>(best, compte.size());
  }
  cout << best << ' ';
  debut = 0;
  while (trains[debut].first < -k) debut++;
  fin = debut;
  compte.clear();
  for (; trains[debut].first < (m / 2) - k; debut++) {
    while (trains[fin].first - trains[debut].first < k) {
      compte.insert(trains[fin].second);
      fin++;
    }
    compte.erase(trains[debut].second);
    if (compte.size() == best) {
      cout << (trains[debut].first + k) << '\n';
      for (int val : compte) {
        cout << (val + 1) << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
  return 0;
}
