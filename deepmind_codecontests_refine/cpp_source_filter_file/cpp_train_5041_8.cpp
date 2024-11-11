#include <bits/stdc++.h>
using namespace std;
int main() {
  int timeOfUse[26] = {0};
  long numOfSubstringWithDiversity[27] = {0};
  char a[300010];
  cin.getline(a, 300010, '\n');
  int countDiversities = 0;
  for (int i = 0; i < strlen(a); i++) {
    if (timeOfUse[a[i] - 'a'] == 0) {
      timeOfUse[a[i] - 'a']++;
      countDiversities++;
    }
  }
  int m = countDiversities;
  cout << countDiversities << endl;
  for (int diversity = 1; diversity <= 26; diversity++) {
    memset(timeOfUse, 0, sizeof timeOfUse);
    countDiversities = 0;
    for (int i = 0, j = 0; i < strlen(a); i++) {
      if (timeOfUse[a[i] - 'a'] == 0) countDiversities++;
      timeOfUse[a[i] - 'a']++;
      for (; countDiversities > diversity; j++) {
        timeOfUse[a[j] - 'a']--;
        if (timeOfUse[a[j] - 'a'] == 0) countDiversities--;
      }
      numOfSubstringWithDiversity[diversity] += i - j + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << numOfSubstringWithDiversity[i] - numOfSubstringWithDiversity[i - 1]
         << endl;
  }
  return 0;
}
