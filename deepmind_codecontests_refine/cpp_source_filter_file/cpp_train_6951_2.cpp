#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,w,k;
	cin>>h>>w>>k;
	string h[6];
	for(int i=0;i<h;i++)
		cin>>s[i];
	int ans =0;
	
	for(int i=0;i<(1<<h);i++)
		for(int j=0;j<(1<<w);j++)
		{
			int cnt = 0;
			for(int x = 0;x < h;x++)
				for(int y = 0;y < w;y++)
					if(!(i>>x&1) and !(j>>y&1))
						cnt += s[x][y]=='#';
		
			ans += cnt==k;
		}
		cout<<ans;
}
