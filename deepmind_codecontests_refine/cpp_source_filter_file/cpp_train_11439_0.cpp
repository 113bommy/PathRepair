#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
	{
        int table[11][11]={0};
        if(n==0)
			break;
        for(int i=0,in;i<n;++i)
		{
            for(int j=0;j<n;++j)
			{
                cin>>in;
                table[i][j]=in;
                table[n][j]+=in;
                table[i][n]+=in;
            }
        }
        for(int i=0;i<n;++i)table[n][n]+=table[n][i];
        for(int i=0;i<n+1;++i)
		{
            for(int j=0;j<n+1;++j)printf("%5d",table[i][j]);
            cout<<endl;
        }
    }
    return 0;