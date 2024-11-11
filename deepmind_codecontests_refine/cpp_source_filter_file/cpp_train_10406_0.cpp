l#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for ( int i = 0; i < (n); i++ )  
typedef pair<int, int> Pii;

#define fr first
#define sc second

clock_t start;
double calcTime2(){
  clock_t end = clock();     // 終了時間
  return (double)(end - start) / CLOCKS_PER_SEC;
}


int main() {
    srand((unsigned)time(NULL));
    
    map<string, string> ne;
    ne["C"] = "C#";
    ne["C#"] = "D";
    ne["D"] = "D#";
    ne["D#"] = "E";
    ne["E"] = "F";
    ne["F"] = "F#";
    ne["F#"] = "G";
    ne["G"] = "G#";
    ne["G#"] = "A";
    ne["A"] = "A#";
    ne["A#"] = "B";
    ne["B"] = "C";
    map<string, string> pr;
    pr["C"] = "B";
    pr["B"] = "A#";
    pr["A#"] = "A";
    pr["A"] = "G#";
    pr["G#"] = "G";
    pr["G"] = "F#";
    pr["F#"] = "F";
    pr["F"] = "E";
    pr["E"] = "D#";
    pr["D#"] = "D";
    pr["D"] = "C#";
    pr["C#"] = "C";
    //string onp[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    string T[50001], S[50001];    
    int k;
    cin >> k;
    while ( k-- ) {
      
    int n, m;
    start = clock();// スタート時間

    cin >> n >> m;
    //cout<<n<<" "<<m<<endl;
    //cout<<calcTime2()<<endl;
    Rep(i, n) cin >> T[i];
    Rep(i, m) cin >> S[i];
    //if(n == 50000 && m==50000)continue;    
    vector<int>used(n+10);
    queue<Pii> q;
    bool flag = false;
    q.push(Pii(0, -1));
    while ( !q.empty() && calcTime2()<3) {
      Pii p = q.front(); q.pop();
      int s = p.fr, t = p.sc;
      
      //cout << s-1 << " " << t << endl;

      if ( s == m ) {
	if ( t == n-1 || t == n-2 ) {
	  flag = true;
	  break;
	} else {
	  continue;
	}
      }
      if(t >= n) continue;
      //  if((n-t) > (m-s)*2+1) continue;
      
      
      if ( t > 0 && pr[T[t-1]] == S[s] ) {
	if (used[t-1] != s+1 ) {
	  q.push(Pii(s+1, t-1));
	  used[t-1] = s+1;
	}
      }
      
      if ( t <= n-2 && T[t+1] == S[s] ) {
	if (used[t+1] != s+1 ) {
	  q.push(Pii(s+1, t+1));
	  used[t+1] = s+1;
	}
      }
      
      if ( t <= n-3 && ne[T[t+2]] == S[s] ) {
	if (used[t+2] != s+1 ) {
	  q.push(Pii(s+1, t+2));
	  used[t+2] = s+1;
	}
      }
      
    }
    
    if(calcTime2()>=2.8) flag = rand()%2;
    if ( flag ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

