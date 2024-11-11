#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

int main(){
  int N, A;
  cin >> N >> A;
  int card[N];
  rep(i,N){
    cin >> card[i];
  }
  int B[A];
  int C[A];
  rep(i,A){
    cin >> B[i] >> C[i];
  }

  priority_queue <pair<int,int>> q;
  rep(i,N){
    q.push(make_pair(A[i],1));
  }
  rep(i,M){
    q.push(make_pair(C[i],B[i]));
  }

  ll ans = 0;

  rep(i,N){
    auto p = q.top();
    q.pop();
    ans += p.first;
    if(p.seconf>1){
      p.second--;
      q.push(p);
    }
  }

  cout << ans << endl;
}
