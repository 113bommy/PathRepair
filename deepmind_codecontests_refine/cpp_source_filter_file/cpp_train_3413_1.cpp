#include <bits/stdc++.h>
#define int long long

using namespace std;

int main(void){

  int X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> p(A),q(B),r(C);
  for(int i=0;i<A;i++) cin >> p[i];
  for(int i=0;i<B;i++) cin >> q[i];
  for(int i=0;i<C;i++) cin >> r[i];

  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());

  for(int i=0;i<X;i++){
    r.push_back(p[i]);
  }
  for(int i=0;i<Y;i++){
    r.push_back(q[i]);
  }

  sort(r.rbegin(),r.rend());
  int ans_sum=0;
  for(int i=0;i<X+Y;++i){
    ans_sum+=r[i];
  }

  cout << ans_sum << "\n";

  return 0;
}
