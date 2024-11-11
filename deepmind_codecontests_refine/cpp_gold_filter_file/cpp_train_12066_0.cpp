#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
int w,h;
vector<int> Xs;
vector<int> Ys;
int n;
int X1[1000];
int Y1[1000];
int X2[1000];
int Y2[1000];
int table[2002][2002];
void dfs(int i, int j){
	table[i][j]=1;
	int dX=1,dY=0;
	for(int k=0;k<4;k++,swap(dX,dY),dX=-dX){
		int X=i+dX;
		int Y=j+dY;
		if(0<=X&&X<Xs.size()&&0<=Y&&Y<Ys.size()&&table[X][Y]==0){
			dfs(X,Y);
		}
	}
}
int main() {
while(1){
	cin >> w >> h;
	if(w==0&&h==0){
		return 0;
	}
	memset(table,0,sizeof(table));
	Xs.clear();
	Xs.push_back(0);
	Ys.push_back(0);
	Xs.push_back(w-1);
	Ys.push_back(h-1);
	Ys.clear();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		Xs.push_back(X1[i]);
		Xs.push_back(X2[i]);
		Ys.push_back(Y1[i]);
		Ys.push_back(Y2[i]);
	}
	sort(Xs.begin(),Xs.end());
	Xs.resize(unique(Xs.begin(),Xs.end())-Xs.begin());
	sort(Ys.begin(),Ys.end());
	Ys.resize(unique(Ys.begin(),Ys.end())-Ys.begin());
	for(int i=0;i<n;i++){
		int s=lower_bound(Xs.begin(),Xs.end(),X1[i])-Xs.begin();
		int t=lower_bound(Ys.begin(),Ys.end(),Y1[i])-Ys.begin();
		int u=lower_bound(Xs.begin(),Xs.end(),X2[i])-Xs.begin();
		int v=lower_bound(Ys.begin(),Ys.end(),Y2[i])-Ys.begin();
		table[s][t]++;
		table[s][v]--;
		table[u][t]--;
		table[u][v]++;
	}
	if(Xs.back()>=w)Xs.pop_back();
	if(Ys.back()>=h)Ys.pop_back();
	for(int i=0;i<Xs.size();i++){
		for(int j=1;j<Ys.size();j++){
			table[i][j]+=table[i][j-1];
		}
	}
	for(int i=1;i<Xs.size();i++){
		for(int j=0;j<Ys.size();j++){
			table[i][j]+=table[i-1][j];
		}
	}
	/*
	for(int j=Ys.size()-1;j>=0;j--){
		for(int i=0;i<Xs.size();i++){
			cout << table[i][j];
		}
		cout << endl;
	}*/
	int ret=0;
	for(int i=0;i<Xs.size();i++){
		for(int j=0;j<Ys.size();j++){
			if(table[i][j]==0){
				//cout << i << ", " << j << endl;
				dfs(i,j);
				ret++;
			}
		}
	}
	cout << ret << endl;

}
}