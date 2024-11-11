#include<iostream>
using namespace std;
int main()
{
  int N,A;int max=0; int some_count=0;
  cin>>N;
  for(int i=0;i<N;i++)
  {
    cin>>A;
    if(A>=max){some_count++;max=A;}
  }
  cout<<count<<endl;
  return 0;
}
