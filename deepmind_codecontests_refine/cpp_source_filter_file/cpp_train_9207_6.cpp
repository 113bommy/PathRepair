#include <bits/stdc++.h>
using namespace std;
int n, a[510], b[510], to[110];
string sa[110], sb[110];
queue<int> qa, qb;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sa[i];
    a[sa[i][0]]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> sb[i];
    b[sb[i][0]]++;
  }
  sort(sa, sa + n);
  sort(sb, sb + n);
  int cnta = 0, cntb = 0;
  int nowa = 0, nowb = 0;
  for (int k = 'A'; k <= 'z'; k++) {
    if (a[k] == 0 && b[k] == 0) {
      continue;
    }
    if (a[k] <= b[k]) {
      if (cnta == 0) {
        for (int i = 0; i < a[k]; i++) {
          to[nowa + i] = nowb + i;
        }
        for (int i = a[k]; i < b[k]; i++) {
          qb.push(nowb + i);
          cntb++;
        }
      } else {
        int s = min(nowb + cnta, nowb + b[k] - a[k]);
        for (int i = 0; i < a[k]; i++) {
          to[nowa + i] = s + i;
        }
        for (int i = nowb; i < s; i++) {
          int x = qa.front();
          qa.pop();
          to[x] = i;
          cnta--;
        }
        for (int i = s + a[k]; i < nowb + b[k]; i++) {
          qb.push(i);
          cntb++;
        }
      }
    } else {
      if (cnta == 0) {
        int s = min(nowa + cntb, nowa + a[k] - b[k]);
        for (int i = 0; i < b[k]; i++) {
          to[s + i] = nowb + i;
        }
        for (int i = nowa; i < s; i++) {
          int x = qb.front();
          qb.pop();
          to[i] = x;
          cntb--;
        }
        for (int i = s + b[k]; i < nowa + a[k]; i++) {
          qa.push(i);
          cnta++;
        }
      } else {
        for (int i = 0; i < b[k]; i++) {
          to[nowa + i] = nowb + i;
        }
        for (int i = b[k]; i < a[k]; i++) {
          qa.push(i);
          cnta++;
        }
      }
    }
    nowa += a[k];
    nowb += b[k];
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << ", ";
    }
    cout << sa[i] << " " << sb[to[i]];
  }
  return 0;
}
