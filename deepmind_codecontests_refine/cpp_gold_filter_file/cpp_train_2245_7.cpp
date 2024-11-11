#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  char road[100];
  bool found;
  cin >> k >> n;
  int g_index, t_index;
  getchar();
  bool arrive = false;
  for (int i = 0; i < k; i++) {
    cin >> road[i];
    if (road[i] == 'G') g_index = i;
    if (road[i] == 'T') t_index = i;
  }
  if (g_index < t_index)
    for (int i = g_index; i <= t_index; i = i + n) {
      if (road[i] == '#') break;
      if (road[i] == 'T') {
        arrive = true;
        break;
      }
    }
  else
    for (int i = g_index; i >= t_index; i = i - n) {
      if (road[i] == '#') break;
      if (road[i] == 'T') {
        arrive = true;
        break;
      }
    }
  if (arrive == true)
    cout << "YES";
  else
    cout << "NO";
}
