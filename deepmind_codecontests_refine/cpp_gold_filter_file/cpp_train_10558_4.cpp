#include <bits/stdc++.h>
using namespace std;
char s1[100], s2[100];
char a1[100], a2[100];
int main() {
  int nums1, nums2, numa1, numa2;
  int numa1q, numa2q;
  memset(s1, '0', sizeof(s1));
  gets(s1);
  gets(s2);
  nums1 = strlen(s1);
  nums2 = strlen(s2);
  int i = 0;
  while (s1[i] != '|') {
    a1[i] = s1[i];
    i++;
  }
  i++;
  int j = 0;
  while (s1[i] != '0') {
    a2[j] = s1[i];
    i++;
    j++;
  }
  numa1 = strlen(a1);
  numa2 = strlen(a2);
  int sum = numa1 + numa2 + nums2;
  int maxnuma = (numa1 > numa2) ? numa1 : numa2;
  if (sum % 2 == 0 && sum / 2 >= maxnuma) {
    numa1q = sum / 2 - numa1;
    numa2q = sum / 2 - numa2;
    int j = 0;
    for (int i = numa1; j < numa1q; i++, j++) {
      a1[i] = s2[j];
    }
    for (int i = numa2; j < sum; i++, j++) {
      a2[i] = s2[j];
    }
    cout << a1;
    cout << "|";
    puts(a2);
  } else
    cout << "Impossible" << endl;
  return 0;
}
