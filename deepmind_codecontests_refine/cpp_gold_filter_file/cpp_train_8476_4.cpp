#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;
const bool testing = false;
void program() {
  float test;
  cin >> test;
  int ok = 1;
  for (int ii = (1), _end = (11); ii < _end; ++ii) {
    for (int jj = (1), _end = (11); jj < _end; ++jj) {
      float i = ii, j = jj;
      if (fabs((i / 2) * j / sqrt(j * j + (i / 2) * (i / 2)) - test) <
          0.000001) {
        cout << i << " " << j << endl;
        ok = 0;
        break;
      }
    }
    if (!ok) break;
  }
}
int main() {
  if (!testing) {
    program();
    return 0;
  }
  FILE* fin = NULL;
  fin = fopen("in.txt", "w+");
  fprintf(fin, "1.200000\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  cout << "Test 1 : \n1.200000\n" << endl;
  cout << "Desired answer:" << endl << "\t3 2\n";
  clock_t startTime1 = clock();
  cout << "Your answer: \n\t";
  program();
  clock_t endTime1 = clock();
  cout << "\nTime: " << double(endTime1 - startTime1) / CLOCKS_PER_SEC
       << " seconds";
  cout << "\n\n\n";
  fin = fopen("in.txt", "w+");
  fprintf(fin, "2.572479\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  cout << "Test 2 : \n2.572479\n" << endl;
  cout << "Desired answer:" << endl << "\t10 3\n";
  clock_t startTime2 = clock();
  cout << "Your answer: \n\t";
  program();
  clock_t endTime2 = clock();
  cout << "\nTime: " << double(endTime2 - startTime2) / CLOCKS_PER_SEC
       << " seconds";
  cout << "\n\n\n";
  fin = fopen("in.txt", "w+");
  fprintf(fin, "4.024922\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  cout << "Test 3 : \n4.024922\n" << endl;
  cout << "Desired answer:" << endl << "\t9 9\n";
  clock_t startTime3 = clock();
  cout << "Your answer: \n\t";
  program();
  clock_t endTime3 = clock();
  cout << "\nTime: " << double(endTime3 - startTime3) / CLOCKS_PER_SEC
       << " seconds";
  cout << "\n\n\n";
  return 0;
}
