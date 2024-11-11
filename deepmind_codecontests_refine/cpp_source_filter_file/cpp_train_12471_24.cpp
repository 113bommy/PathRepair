#include <cstdio>
using namespace std;
int main () {
  int A, B;
  cin >> A >> B;
  cout << max(0, A - B - B) << endl;
}