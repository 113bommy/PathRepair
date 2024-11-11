#include <iostream>
using namespace std;
 
int main() {
  int N;
  int K;
  char S[55];
  
  cin >> N >> K >> S;
  S[K-1]+=32;
  cout << S << endl;

}
