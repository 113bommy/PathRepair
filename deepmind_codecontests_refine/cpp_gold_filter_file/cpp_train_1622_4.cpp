#include <bits/stdc++.h>
using namespace std;
string can_split(int p[], int n) {
  for (int i = 0; i < n; i++) {
    if (p[i] != 0) break;
    if (i == n - 1) return "NO";
  }
  return "YES";
}
int split(int br_str, int pocetni[], int zavrsni[], int p[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += p[i];
  }
  if (sum != 0) return 1;
  for (int i = n - 1; i >= 0; i--) {
    if (p[i] != 0) {
      zavrsni[0] = i;
      pocetni[1] = i + 1;
      break;
    }
  }
  br_str++;
  zavrsni[1] = n;
  return br_str;
}
int main(int argc, char **argv) {
  int n, p[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  string temp = can_split(&p[0], n);
  cout << temp << endl;
  int br_str = 1, pocetni[2] = {1}, zavrsni[2] = {n};
  if (temp == "YES") {
    br_str = split(br_str, &pocetni[0], &zavrsni[0], &p[0], n);
    cout << br_str << endl;
    for (int i = 0; i < br_str; i++)
      cout << pocetni[i] << " " << zavrsni[i] << endl;
  }
  return 0;
}
