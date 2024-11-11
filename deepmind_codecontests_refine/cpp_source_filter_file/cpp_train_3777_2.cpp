#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, d, e, f, g, h;
  cin >> n;
  vector<long long int> values(n), kalues(n), malues;
  for (int i = 0; i < n; i++) {
    cin >> values[i];
    cin >> kalues[i];
    kalues[i]--;
    malues.push_back(values[i]);
    malues.push_back(kalues[i]);
  }
  sort(values.begin(), values.end());
  sort(kalues.begin(), kalues.end());
  sort(malues.begin(), malues.end());
  long long int mini = -5, year = -1;
  malues.erase(unique(malues.begin(), malues.end()), malues.end());
  for (int i = 0; i < 2 * n; i++) {
    long long int helebele =
        lower_bound(kalues.begin(), kalues.end(), malues[i]) - kalues.begin();
    helebele += n - (upper_bound(values.begin(), values.end(), malues[i]) -
                     values.begin());
    if (mini < n - helebele) mini = n - helebele, year = malues[i];
  }
  cout << mini << " " << year << endl;
}
