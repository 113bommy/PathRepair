#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	if(i==2){
		cout << -1 << "\n";
		return 0;
	}
	if(n%3==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i%3==2){
					if(j%3==0){
						cout << ".";
					}else{
						cout << "a";
					}
				}else{
					if(j%3==0){
						cout << "a";
					}else{
						cout << ".";
					}
				}
			}
			cout << "\n";
		}
		return 0;
	}
	vector<vector<char>> p4=
	{
		{'a','a','c','d'},
		{'b','b','c','d'},
		{'c','d','a','a'},
		{'c','d','b','b'}
	};
	
	vector<vector<char>> p5=
	{
		{'a','a','d','e','e'},
		{'b','b','d','.','f'},
		{'c','c','g','g','f'},
		{'.','.','a','b','c'},
		{'.','.','a','b','c'}
	};
	vector<vector<char>> p7=
	{
		{'a','a','.','a','a','.','a'},
		{'.','b','b','.','.','b','a'},
		{'a','.','a','a','.','b','.'},
		{'a','.','.','.','a','.','a'},
		{'.','b','.','.','a','.','a'},
		{'a','b','.','.','b','b','.'},
		{'a','.','a','a','.','a','a'}
	};
	vector<vector<char>> res(n,vector<char>(n,'.'));
	vector<vector<int>> dec(n+10);
	dec[4].push_back(4);
	dec[5].push_back(5);
	dec[7].push_back(7);
	for(int i=8;i<=n;i++){
		if(dec[i-4].size()>0){
			dec[i]=dec[i-4];
			dec[i].push_back(4);
		}else if(dec[i-5].size()>0){
			dec[i]=dec[i-5];
			dec[i].push_back(5);
		}else if(dec[i-7].size()>0){
			dec[i]=dec[i-7];
			dec[i].push_back(7);
		}
	}
	int ind=0;
	for(int d:dec[n]){
		if(d==4){
			for(int i=0;i<d;i++){
				for(int j=0;j<d;j++){
					res[i+ind][j+ind]=p4[i][j];
				}
			}
		}
		if(d==5){
			for(int i=0;i<d;i++){
				for(int j=0;j<d;j++){
					res[i+ind][j+ind]=p5[i][j];
				}
			}
		}
		if(d==7){
			for(int i=0;i<d;i++){
				for(int j=0;j<d;j++){
					res[i+ind][j+ind]=p7[i][j];
				}
			}
		}
		ind+=d;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << res[i][j];
		}
		cout << "\n";
	}
	return 0;
}