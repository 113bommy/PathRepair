#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=1;i<=n;i++)
int jj[1002][1002];
int oo[1002][1002];
int ii[1002][1002];

int main(){
  int m,n,k;
  cin>>m>>n>>k;
  char c;
  loop(i,m)loop(j,n){
    cin>>c;
    jj[i][j]=jj[i-1][j]+jj[i][j-1]-jj[i-1][j-1];
    oo[i][j]=oo[i-1][j]+oo[i][j-1]-oo[i-1][j-1];
    ii[i][j]=ii[i-1][j]+ii[i][j-1]-ii[i-1][j-1];
    if(c=='J')jj[i][j]++;
    if(c=='O')oo[i][j]++;
    if(c=='I')ii[i][j]++;
  }
  int a,b,c,d;
  loop(i,k){
    cin>>a>>b>>c>>d;
    a--;
    b--;
    cout<<(jj[c][d]-jj[a][d]-jj[c][b]+jj[a][b]);
    cout<<" ";
    cout<<(oo[c][d]-oo[a][d]-oo[c][b]+oo[a][b]);
    cout<<" ";
    cout<<(ii[c][d]-ii[a][d]-ii[c][b]+ii[a][b]);
    cout<<endl;
  }
  return 0;
}