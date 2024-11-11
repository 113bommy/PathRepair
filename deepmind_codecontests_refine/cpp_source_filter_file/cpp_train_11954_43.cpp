#include <iostream>
using namespace std;

int main(void)
{
  int N,K; cin>>N>>K;
  cout << (N%K!=0)?1:0 << endl;
  return 0;
}