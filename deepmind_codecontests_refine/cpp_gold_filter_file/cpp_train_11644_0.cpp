#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  cout << (100 * (N - M) + 1900 * M) * pow(2, M) << endl;
}
