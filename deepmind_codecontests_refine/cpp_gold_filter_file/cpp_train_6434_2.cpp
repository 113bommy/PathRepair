# include<bits/stdc++.h>
using namespace std;
int main(){
int n, m;
  cin >> n >> m;
  int L[m], R[m];
  for (int i = 0; i < m; i++){
  	cin >> L[i] >> R[i];
  }
  cout << max(0,*min_element(R,R+m)-*max_element(L,L+m)+1)<<'\n';

	return 0;
}