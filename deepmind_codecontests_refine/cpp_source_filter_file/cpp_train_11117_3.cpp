#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M,AnsAC=0,AnsWA=0;
  cin>>N>>M;
  vector<int> AC(N),WA(N);
  int p;
  string S;
  rep(i,M){cin>>p>>S;
           if(AC.at(p-1)==0){if(S=="AC"){AC.at(p-1)++;}else{WA.at(p-1)++;}}
          }
  rep(i,N){AnsAC+=AC.at(i);AnsWA=+=AC.at(i)*WA.at(i);}
  cout<<AnsAC<<" "<<AnsWA<<endl;
}
