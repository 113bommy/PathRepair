include<iostream>
 
using namespace std;
 
int main()
{
  	long long n;
  	cin>>n;
  	long long a,s=0;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    s+=a;
  }
  cout<<s-n<<endl;
}