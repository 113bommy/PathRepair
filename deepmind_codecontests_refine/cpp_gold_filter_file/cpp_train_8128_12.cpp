#include <bits/stdc++.h>
using namespace std;
struct letters {
  int cnt;
  char c;
  bool operator<(const letters &d) const { return cnt < d.cnt; }
} A[100];
string s;
bool done[30];
int main() {
  int i, j = 0, k;
  memset(done, false, 28 * sizeof(bool));
  cin >> s >> k;
  for (i = 0; i < 30; i++) {
    A[i].cnt = 0;
    A[i].c = 'a' + i;
  }
  for (i = 0; i < s.size(); i++) {
    A[s[i] - 'a'].cnt++;
    if (!done[s[i] - 'a']) {
      done[s[i] - 'a'] = true;
      j++;
    }
  }
  sort(A, A + 26);
  i = 0;
  while (k > 0 && i < 26) {
    if (k >= A[i].cnt && A[i].cnt > 0) {
      k -= A[i].cnt;
      done[A[i].c - 'a'] = false;
      j--;
    }
    i++;
  }
  printf("%d\n", j);
  for (i = 0; i < s.size(); i++)
    if (done[s[i] - 'a']) printf("%c", s[i]);
  printf("\n");
  ;
  return 0;
}
