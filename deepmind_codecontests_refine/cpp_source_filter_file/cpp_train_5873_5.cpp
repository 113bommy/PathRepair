#include <bits/stdc++.h>
using namespace std;
const bool testing = true;
void program() {
  long long n;
  cin >> n;
  vector<int> type(n + 1, 0);
  vector<int> a(n + 1, 0);
  vector<int> count(n + 1, 0);
  type[0] = 999999;
  a[0] = 999999;
  count[0] = 999999;
  for (int i = (1), _end = (n + 1); i < _end; ++i) cin >> type[i];
  for (int i = (1), _end = (n + 1); i < _end; ++i) {
    cin >> a[i];
    count[a[i]]++;
  }
  int mx = 0;
  vector<int> seqnc;
  for (int i = (1), _end = (n + 1); i < _end; ++i) {
    if (type[i] == 1 && count[i] <= 1) {
      vector<int> seq;
      seq.push_back(i);
      int c = 1;
      int j = a[i];
      while (type[j] != 1 && a[j] != 0 && count[j] == 1) {
        c++;
        seq.push_back(j);
        j = a[j];
      }
      if (type[j] == 0 && count[j] == 1) {
        c++;
        seq.push_back(j);
      }
      if (c > mx) {
        mx = c;
        seqnc = seq;
      }
    }
  }
  cout << mx << "\n";
  for (int i = seqnc.size() - 1; i >= 0; i--) cout << seqnc[i] << " ";
  cout << "\n";
}
int main() {
  if (!testing) {
    program();
    return 0;
  }
  FILE* fin = NULL;
  fin = fopen("in.txt", "w+");
  fprintf(fin, "5\n0 0 0 0 1\n0 1 2 3 4\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(1) => expected : \n");
  printf("5\n1 2 3 4 5\n");
  printf("test case(1) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "5\n0 0 1 0 1\n0 1 2 2 4\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(2) => expected : \n");
  printf("2\n4 5\n");
  printf("test case(2) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "4\n1 0 0 0\n2 3 4 2\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(3) => expected : \n");
  printf("1\n1\n");
  printf("test case(3) => founded  : \n");
  program();
  return 0;
}
