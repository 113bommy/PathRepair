#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  string B[n];
  for(int i=0;i<n;i++) cin >> B[i];
  int m;
  cin >> m;
  string C[m];
  for(int i=0;i<m;i++)cin >> C[i];
  int A=-;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int k=i;k<n;k++){if(B[i]==B[k]) sum++;}
    for(int l=0;l<m;l++){if(B[i]==C[l]) sum--;} 
    A=max(A,sum);
  }
   cout << A <<endl;
  }
  