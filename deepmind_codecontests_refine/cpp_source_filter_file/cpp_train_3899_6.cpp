#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int fruit_axis[3001];
  for (int i = 0; i < 3001; i++) fruit_axis[i] = 0;
  for (int i = 0; i < n; i++) {
    int day_ripen, n_fruit;
    cin >> day_ripen >> n_fruit;
    fruit_axis[day_ripen] += n_fruit;
  }
  int total = 0;
  for (int i = 1; i <= 3000; i++) {
    int minim = min(fruit_axis[i - 1], v);
    total += minim;
    fruit_axis[i - 1] -= minim;
    minim = min(fruit_axis[i], v - minim);
    total += minim;
    fruit_axis[i] -= minim;
  }
  cout << total << endl;
  return 0;
}
