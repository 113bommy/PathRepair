#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, k, start = 0, end = 0, ea = -9000000001, cea = 0,
                        cutdown = 0, cutdownc = 0, treecount = 0,
                        treecountc = 0;
  long long a[300000];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (a[i] == a[j]) {
        cea = 0;
        cutdownc = 0;
        treecountc = 2;
        cea += (a[i] + a[j]);
        for (k = i + 1; k < j; k++) {
          if (a[k] >= 0) {
            cea += a[k];
            treecountc++;
          } else
            cutdownc++;
        }
        if (cea > ea) {
          start = i;
          end = j;
          ea = cea;
          cutdown = cutdownc;
          treecount = treecountc;
        } else if ((cea == ea) && (treecountc > treecount)) {
          start = i;
          end = j;
          ea = cea;
          cutdown = cutdownc;
          treecount = treecountc;
        } else if ((cea == ea) && (a[i] > a[start])) {
          start = i;
          end = j;
          ea = cea;
          cutdown = cutdownc;
          treecount = treecountc;
        }
      }
    }
  }
  cutdown += (start + n - end - 1);
  cout << ea << " " << cutdown << "\n";
  for (i = 0; i < start; i++) cout << i + 1 << " ";
  for (i = start + 1; i < end; i++) {
    if (a[i] < 0) cout << i + 1 << " ";
  }
  for (i = end + 1; i < n; i++) cout << i + 1 << " ";
  return 0;
}
