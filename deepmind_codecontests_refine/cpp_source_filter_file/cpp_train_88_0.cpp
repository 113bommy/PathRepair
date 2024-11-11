<iostream>
using namespace std;

int main()
{
  int n;
  for(;cin>>n,n;)
    {
      int data[n];
      long long int step=0;
      for(int i=0;i<n;i++)
	cin>>data[i];
      
      for(int i=0;i<n;i++)
	for(int j=0;j<n-i-1;j++)
	  {
	    if(data[j]>data[j+1])
	      {
		swap(data[j],data[j+1]);
		step++;
	      }
	  }
      cout<<step<<endl;
    }
}