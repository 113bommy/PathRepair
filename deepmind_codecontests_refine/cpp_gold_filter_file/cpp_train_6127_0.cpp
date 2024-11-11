#include <iostream>
using namespace std;
int main(){
  long long int N, M;
  cin >> N >> M;
  cout << min(N, M/2) + max(0LL,(M-2*N)/4) << endl;
  return 0;
}
