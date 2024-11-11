#include<bits/stdc++.h>
using namespace std;
typedef struct{
  int first,second;
  long long place;
}PA;
vector<PA> vec;

void east(int n,long long place){
  if(vec[n].second == 1){
    vec[n].place = place;
    east(n-1,place);
  }
}

void west(int n,long long place){
  if(vec[n].second == 2){
    vec[n].place = place;
    west(n+1,place);
  }
}

int main(){
  int n,q,b,c;
  long long t,a;
      
  scanf("%d %lld %d",&n,&t,&q);
  
  for(int i=0;i<n;i++){
    scanf("%lld %d",&a,&b);
    vec.push_back( (PA){a,b,LLONG_MAX});
  }
  
  for(int i=0;i<n-1;i++){
    if( vec[i].second == 1 && vec[i+1].second == 2){
      vec[i].place = (vec[i].first+vec[i+1].first)/2;
      east(i-1,vec[i].place);
      west(i+1,vec[i].place);
    }
  }

  for(int i=0;i<q;i++){
    scanf("%d",&c);
    c--;
    
    if(vec[c].place == LLONG_MAX || llabs(vec[c].first-vec[c].place) > t){
      if(vec[c].second == 1) cout << vec[c].first+t << endl;
      if(vec[c].second == 2) cout << vec[c].first-t << endl;
    } else cout << vec[c].place << endl;
  }
  return (0);
}