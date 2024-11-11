#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long> rods;
  long max = 0;
  long sum = 0;
  for (int i = 0; i < n; i++) {
    long aux;
    cin >> aux;
    rods.push_back(aux);
    sum += aux;
    if (max < aux) {
      max = aux;
    }
  }
  long ret = max - (sum - max) + 1;
  printf("%d", ret);
}
