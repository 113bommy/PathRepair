#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
template <class T>
void out(map<char, T> &a, string s = "(%3c ->%3d)") {
  for (auto(it) = (a).begin(); (it) != (a).end(); ++(it))
    printf(s.c_str(), it->first, it->second);
  printf("\n");
}
template <class T>
void out(vector<T> &a, string s = "%3d ") {
  int i, n = a.size();
  for ((i) = 0; (i) < (n); (i)++) printf(s.c_str(), a[i]);
  printf("\n");
}
template <class T>
void out(T *a, int n, string s = "%3d ") {
  int i;
  for ((i) = 0; (i) < (n); (i)++) printf(s.c_str(), a[i]);
  printf("\n");
}
long long i, j, N, M, n, m, k, p;
int MainSolve(string args = "") {
  cout << args;
  long long n, a, b, z;
  cin >> n >> a >> b;
  for ((i) = 0; (i) < (n); (i)++) {
    cin >> z;
    cout << ((a % b) * (z % b) % b) << " ";
  }
  cout << endl;
  return 0;
}
string ReadAllLines(char *fileName) {
  string s = "";
  const int NMAX = 1000;
  char buf[NMAX];
  buf[0] = 0;
  FILE *f = fopen(fileName, "r");
  while (fgets(buf, NMAX, f)) s = s + string(buf);
  return string(s.begin(), find_if(s.rbegin(), s.rend(), [](char c) {
                             return c != '\n' && c != '\r' && c != '\t' &&
                                    c != ' ';
                           }).base());
}
int main() {
  MainSolve();
  return 0;
}
