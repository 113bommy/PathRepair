#include <bits/stdc++.h>
using namespace std;
string a[101];
int num[101];
int taxi[101];
int pizza[101];
int girls[101];
int k1, k2, k3;
int maxg = 1, maxt = 1, maxp = 1;
int main() {
  int n;
  cin >> n;
  string b;
  for (int i = 0; i < n; i++) {
    cin >> num[i] >> a[i];
    int tax = 0, piz = 0, girl = 0;
    for (int j = 0; j < num[i]; j++) {
      cin >> b;
      bool ans = false, ans2 = false;
      char c;
      int countt = 0, countp = 0;
      for (int i = 0; i < 8; i++) {
        if (b[i] == '-') {
          continue;
        }
        if (i == 0) {
          c = b[i];
        }
        if (i != 0) {
          if (b[i] == c) {
            countt++;
            ans = true;
          } else if (b[i] < c) {
            ans = false;
            c = b[i];
            ans2 = true;
            countp++;
          } else {
            ans2 = false;
            ans = false;
            break;
          }
        }
      }
      if (ans && countt == 5) {
        tax++;
      } else if (ans2 && countp == 5) {
        piz++;
      } else {
        girl++;
      }
    }
    if (tax > maxt) {
      maxt = tax;
    }
    if (piz > maxp) {
      maxp = piz;
    }
    if (girl > maxg) {
      maxg = girl;
    }
    taxi[i] = tax;
    pizza[i] = piz;
    girls[i] = girl;
  }
  bool intt = false;
  bool inpp = false;
  bool ingg = false;
  cout << "If you want to call a taxi, you should call: ";
  for (int i = 0; i < n; i++) {
    if (taxi[i] == maxt && !intt) {
      cout << a[i];
      intt = true;
    } else if (taxi[i] == maxt && intt) {
      cout << ", " << a[i];
    }
  }
  cout << ".\n";
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < n; i++) {
    if (pizza[i] == maxp && !inpp) {
      cout << a[i];
      inpp = true;
    } else if (pizza[i] == maxp && inpp) {
      cout << ", " << a[i];
    }
  }
  cout << ".\n";
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < n; i++) {
    if (girls[i] == maxg && !ingg) {
      cout << a[i];
      ingg = true;
    } else if (girls[i] == maxg && ingg)
      cout << ", " << a[i];
  }
  cout << ".";
}
