#include <bits/stdc++.h>
using namespace std;
int A[20][20];
long long T[20];
int num(string i) {
  if (i == "Anka")
    return 0;
  else if (i == "Chapay")
    return 1;
  if (i == "Cleo") return 2;
  if (i == "Troll") {
    return 3;
  }
  if (i == "Dracul") {
    return 4;
  }
  if (i == "Snowy") return 5;
  if (i == "Hexadecimal") return 6;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string f, s, temp;
    cin >> f >> temp >> s;
    A[num(f)][num(s)] = 1;
  }
  long long a, b, c;
  cin >> a >> b >> c;
  long long good = 90000000000LL;
  int a_g = 0, b_g = 0, c_g = 0;
  for (int i = 1; i < 7; i++) {
    for (int j = 1; j < 7; j++) {
      for (int k = 1; k < 7; k++) {
        if (i + j + k == 7) {
          T[0] = a / i;
          T[1] = b / j;
          T[2] = c / k;
          sort(T, T + 3);
          if (T[2] - T[0] < good) {
            good = T[2] - T[0];
            a_g = i;
            b_g = j;
            c_g = k;
          }
        }
      }
    }
  }
  for (int i = 0; i < 7; i++) T[i] = i;
  int max_dr = 0;
  do {
    int sum = 0;
    for (int i = 0; i < a_g; i++) {
      for (int j = 0; j < a_g; j++) {
        if (A[T[i]][T[j]]) sum++;
      }
    }
    for (int i = a_g; i < a_g + b_g; i++) {
      for (int j = a_g; j < a_g + b_g; j++) {
        if (A[T[i]][T[j]]) sum++;
      }
    }
    for (int i = a_g + b_g; i < a_g + b_g + c_g; i++) {
      for (int j = a_g + b_g; j < a_g + b_g + c_g; j++) {
        if (A[T[i]][T[j]]) sum++;
      }
    }
    if (sum > max_dr) max_dr = sum;
  } while (next_permutation(T, T + 7));
  cout << good << " " << max_dr;
  return 0;
}
