#include <bits/stdc++.h>
int main() {
  unsigned short nRooms;
  scanf("%hu", &nRooms);
  unsigned short i;
  for (i = 0; i < nRooms; i++) {
    unsigned short maxRadiators, nSections;
    scanf("%hu %hu", &maxRadiators, &nSections);
    unsigned int cost = pow(nSections / maxRadiators, 2) * maxRadiators;
    cost -= pow(nSections / maxRadiators, 2) * (nSections % maxRadiators);
    cost += pow((nSections / maxRadiators) + 1, 2) * (nSections % maxRadiators);
    printf("%d", cost);
  }
  return 0;
}
