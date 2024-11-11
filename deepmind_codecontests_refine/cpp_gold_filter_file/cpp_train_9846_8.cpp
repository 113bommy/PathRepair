#include <bits/stdc++.h>
using namespace std;
void tolow(string& s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 91) s[i] += 32;
  }
}
int czypierwsza(int n) {
  int suma = 2;
  int check = 1;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) suma++;
    if (suma > 2) {
      check = 0;
      break;
    }
  }
  if (check == 0)
    return 0;
  else
    return 1;
}
int NWD(int a, int b) {
  int pom;
  while (b != 0) {
    pom = b;
    b = a % b;
    a = pom;
  }
  return a;
}
int czypot(int k) {
  int z = 1;
  int pot = 2;
  int j = 1;
  if (k % 2 == 0) return 0;
  while (z < k) {
    z += pow(pot, j);
    j++;
  }
  if (z == k)
    return 1;
  else
    return 0;
}
void solve() {
  int n;
  cin >> n;
  int x;
  vector<int> tab;
  for (int i = 0; i < n; i++) {
    cin >> x;
    tab.push_back(x);
  }
  sort(tab.begin(), tab.end());
  for (int i = 0; i < n - 1; i++) {
    if (n == 1) {
      break;
    }
    for (int j = i + 1; j < n; j++) {
      if (abs(tab[i] - tab[j]) <= 1) {
        if (tab[i] >= tab[j]) {
          tab.erase(tab.begin() + j);
        } else {
          tab.erase(tab.begin() + i);
        }
        n--;
        i = -1;
        break;
      }
    }
  }
  if (n == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main(int argc, char** argv) {
  int n;
  cin >> n;
  int tab[n];
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    if (tab[i] > max) max = tab[i];
  }
  if (n == 1)
    cout << "0";
  else {
    int suma = 0;
    for (int i = 0; i < n; i++) {
      suma = suma + (max - tab[i]);
    }
    cout << suma;
  }
  return 0;
}
