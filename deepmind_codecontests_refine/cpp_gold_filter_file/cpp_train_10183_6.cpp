#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n,k;
  	cin >>n >>k;
  	vector<vector<int>> ds(n);
  	rep(i,n){
    	int t,d;
      	cin >>t >>d;t--;
      	ds[t].push_back(d);
    }
  	vector<int> y0,y1;
  	rep(i,n){
    	if(ds[i].size()==0) continue;
      	sort(ds[i].begin(),ds[i].end());
      	y1.push_back(ds[i].back());
      	ds[i].pop_back();
      	y0.insert(y0.end(), ds[i].begin(), ds[i].end());
    }//y1には各種類の最大、y0はそれ以外を昇順で
  	sort(y0.rbegin(), y0.rend());
    sort(y1.rbegin(), y1.rend());//それぞれ降順
  	long long ans=0;
  	int Y=max(0,k-int(y0.size()));
    long long X=0;
  	rep(i,Y)   X +=y1[i]; //種類がk個に満たない時
  	rep(i,k-Y) X +=y0[i];
  	while(1){
    	ans=max(ans, X+(long long)Y*Y);
      	if(Y >= k || Y >= y1.size()) break;
      	X += y1[Y];
      	X -= y0[k-Y-1];
      	++Y;
    }
    cout <<ans <<endl;
  return 0;

}
