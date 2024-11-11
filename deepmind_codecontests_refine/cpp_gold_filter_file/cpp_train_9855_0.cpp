#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> num;
  long long int n;
  int ar2[2] = {4, 7};
  int ar4[4] = {4, 4, 7, 7};
  int ar6[6] = {4, 4, 4, 7, 7, 7};
  int ar8[8] = {4, 4, 4, 4, 7, 7, 7, 7};
  int ar10[10] = {4, 4, 4, 4, 4, 7, 7, 7, 7, 7};
  n = 0;
  for (int i = 0; i < 2; i++) n = n * 10 + ar2[i];
  num.push_back(n);
  while (next_permutation(ar2, ar2 + 2)) {
    n = 0;
    for (int i = 0; i < 2; i++) n = n * 10 + ar2[i];
    num.push_back(n);
  }
  n = 0;
  for (int i = 0; i < 4; i++) n = n * 10 + ar4[i];
  num.push_back(n);
  while (next_permutation(ar4, ar4 + 4)) {
    n = 0;
    for (int i = 0; i < 4; i++) n = n * 10 + ar4[i];
    num.push_back(n);
  }
  n = 0;
  for (int i = 0; i < 6; i++) n = n * 10 + ar6[i];
  num.push_back(n);
  while (next_permutation(ar6, ar6 + 6)) {
    n = 0;
    for (int i = 0; i < 6; i++) n = n * 10 + ar6[i];
    num.push_back(n);
  }
  n = 0;
  for (int i = 0; i < 8; i++) n = n * 10 + ar8[i];
  num.push_back(n);
  while (next_permutation(ar8, ar8 + 8)) {
    n = 0;
    for (int i = 0; i < 8; i++) n = n * 10 + ar8[i];
    num.push_back(n);
  }
  n = 0;
  for (int i = 0; i < 10; i++) n = n * 10 + ar10[i];
  num.push_back(n);
  while (next_permutation(ar10, ar10 + 10)) {
    n = 0;
    for (int i = 0; i < 10; i++) n = n * 10 + ar10[i];
    num.push_back(n);
  }
  int x;
  cin >> x;
  for (int i = 0; i < num.size(); i++) {
    if (num[i] >= x) {
      cout << num[i];
      break;
    }
  }
}
