#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;K;
  cin>>N>>K;
  double s=0;
  for(int i=1;i<N=1;i++)
  {
    double ss=1;
    int b=i;
    while(b<K)
    {
      ss/=2;
      b*=2
    }
    s+=ss;
  }
  s/=3;
  cout<<fixed<<setprecision(10)<<s<<endl;
}