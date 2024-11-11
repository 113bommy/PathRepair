#include<bits/stdc++.h>
using namespace std;

int main() 
{
  int A, B, C, x;
  cin>>A>>B>>C;
  x=((A==B)+(B==C)+(C==A));
  if(x==1)
  { cout<<"Yes";
  }
  else 
    cout<<"No";
  return 0;
}
