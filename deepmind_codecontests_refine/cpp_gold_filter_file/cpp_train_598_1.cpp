#include <bits/stdc++.h>
using namespace std;

int main()
{
  	long long int n; cin >> n;
  	vector<long long int> a(n);
  	for(auto &x: a) cin >> x;
  	
  	long long int money = 1000;
  	for(int i = 0 ; i < n - 1 ; i++) {
    	long long int stocks = money/a[i];
      	money += stocks*max(a[i+1] - a[i], 0LL);
    }
  	cout << money << endl;
  	return 0;
}