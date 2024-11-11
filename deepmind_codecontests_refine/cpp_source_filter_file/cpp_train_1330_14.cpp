#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  cin>>n;
  if(n%10==3)
    cout<<"bon";
  else if(n%10==0||n%10==1||n%10==6||n%1===8)
    cout<<"pon";
  else
    cout<<"hon";
}