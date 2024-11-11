#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> speedpot[200050];
pair<long long, long long> warppot[200050];
int main() {
  long long pot, speed, warp;
  cin >> pot >> speed >> warp;
  long long normalspeed, mana;
  cin >> normalspeed >> mana;
  long long timp = pot * normalspeed;
  for (long long i = 1; i <= speed; i++) {
    cin >> speedpot[i].first;
  }
  for (long long i = 1; i <= speed; i++) {
    cin >> speedpot[i].second;
  }
  for (long long i = 1; i <= warp; i++) {
    cin >> warppot[i].first;
  }
  for (long long i = 1; i <= warp; i++) {
    cin >> warppot[i].second;
  }
  for (long long i = 1; i <= warp; i++) {
    if (mana >= warppot[i].second) {
      if (warppot[i].first >= pot) {
        timp = 0;
      } else {
        timp = min(timp, (pot - warppot[i].first) * normalspeed);
      }
    }
  }
  for (long long i = 1; i <= speed; i++) {
    if (mana >= speedpot[i].second) {
      long long val = mana - speedpot[i].second;
      long long st = 0;
      long long dr = warp;
      long long gasit;
      while (st < dr) {
        long long mij = (st + dr) / 2;
        if (warppot[mij].second > val) {
          dr = mij - 1;
          continue;
        }
        if (warppot[mij].second <= val) {
          st = mij + 1;
          gasit = mij;
          continue;
        }
      }
      timp = min(timp, (pot - warppot[i].first) * speedpot[i].first);
    }
  }
  cout << timp;
  return 0;
}
