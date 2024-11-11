#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int arr1[100009], arr2[100009], na, nb, k, m, i;
  cin >> na >> nb;
  cin >> k >> m;
  for (i = 1; i <= na; i++) cin >> arr1[i];
  for (i = 1; i <= nb; i++) cin >> arr2[i];
  if (arr1[k] < arr2[nb - m + 1])
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
