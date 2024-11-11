#include <bits/stdc++.h>
using namespace std;
int sub_sequence(char ar[], int k) {
  vector<int> hash(k, 0);
  for (int i = 0; ar[i] != '\0'; i++) hash[ar[i] - 'A']++;
  int min_val = INT_MAX;
  for (int i = 0; i < k; i++) min_val = min_val > hash[i] ? hash[i] : min_val;
  return min_val * k;
}
int main() {
  int n, k;
  cin >> n >> k;
  char ar[n + 1];
  char c;
  int i = 0;
  while (i < n) {
    c = getc(stdin);
    ar[i++] = c;
  }
  ar[i] = '\0';
  cout << sub_sequence(ar, k);
  return 0;
}
