#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int N;
  long long K;
  cin >> N >> K;
  vector<int> A(N+1);
  for(int i = 1; i < N+1; i++){
    cin >> A.at(i);
  }
  
  int c = 1;
  while(K){
    if(K&1) c = A.at(c);
    vector<int> NA(N+1);
    for(int i = 1;i < N+1; i++){
      NA.at(i) = A.at(A.at(i));
    }
    A.swap(NA);
    K >>= 1;
  }
  cout << c << "\n";
}
