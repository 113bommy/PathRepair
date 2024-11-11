#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

int main(){
    int n,z,w
    cin >> n >> z >> w;
 	vector<int> a(n);
    rep(i,n) cin >> a[i];
    if(n == 1){
		cout << abs(a[n-1] - w) << endl;
    }else{
    	cout << max(abs(a[n-1] - w), abs(a[n-1] - a[n-2])) << endl;
    }
}
