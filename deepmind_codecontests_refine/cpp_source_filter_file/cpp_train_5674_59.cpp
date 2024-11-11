#include <bits/stdc++.h>
using namespace std;
int max(int a[], int s) {
  int m = a[0];
  for (int i = 1; i < s; i++) {
    if (a[i] > m) {
      m = a[i];
    }
  }
  return m;
}
int maxI(int a[], int s) {
  int m = a[0], ii = 0;
  for (int i = 1; i < s; i++) {
    if (a[i] > m) {
      m = a[i];
      ii = i;
    }
  }
  return ii;
}
int min(int a[], int s, int s1) {
  int *freq = new int[s1];
  for (int i = 0; i < s; i++) {
    freq[a[i]]++;
  }
  return maxI(freq, s1);
}
int maxII(int a[], int s, int b[]) {
  int m = a[0], ii = 0;
  for (int i = 1; i < s; i++) {
    if (a[i] > m) {
      m = a[i];
      ii = i;
    } else {
      if (a[i] == m) {
        if (b[i] < b[ii]) {
          m = a[i];
          ii = i;
        }
      }
    }
  }
  return ii;
}
int main() {
  int candy, cities;
  cin >> candy >> cities;
  int *winners = new int[cities];
  int *winnersI = new int[cities];
  int *votes = new int[candy];
  for (int i = 0; i < cities; i++) {
    for (int i = 0; i < candy; i++) {
      cin >> votes[i];
    }
    winners[i] = max(votes, candy);
    winnersI[i] = maxI(votes, candy);
  }
  cout << min(winnersI, cities, candy) + 1;
  return 0;
}
