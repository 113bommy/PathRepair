#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long int, long long int> > res;
  long long int tam;
  scanf("%I64d", &tam);
  long long int arr[tam + 5];
  for (int i = 0; i < tam; i++) {
    scanf("%I64d", &arr[i]);
  }
  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - i; j++) {
      if (arr[j] > arr[j + 1]) {
        long long int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        res.push_back(pair<long long int, long long int>(j + 1, j + 2));
      }
    }
  }
  int siz = res.size();
  for (int i = 0; i < siz; i++) {
    printf("%I64d %I64d\n", res[i].first, res[i].second);
  }
  return 0;
}
