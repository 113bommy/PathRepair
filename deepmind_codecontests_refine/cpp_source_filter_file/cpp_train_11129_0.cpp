#include<cstdio>
#include<vector>
using namespace std;

int main(){
  int N, K;
  while( scanf("%d %d", &N, &K), N||K ){
    vector<int> bloods;
    for( int i=0; i<K; i++ ){
      int b;
      scanf("%d", &b);
      bloods.push_back(b);
    }

    for( int i=0; i<N; i++ ){
      for( int j=0; j<K; j++ ){
        int b;
        scanf("%d", &b );
        bloods[j] -= b;
      }
    }
    bool runout = false;
    for( int i=0; i<K; i++ ){
      if( bloods[j] < 0 ){
        runout = true;
        break;
    }
    printf(runout?"No\n":"Yes\n");
  }
  return 0;
}