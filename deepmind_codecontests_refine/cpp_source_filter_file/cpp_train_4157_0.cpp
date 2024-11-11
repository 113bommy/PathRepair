#include <fstream>
#include <vector>

using namespace std;

int main(){
	int n, m ,k;
	while(cin >> n >> m >> k, n){
		vector<double> cur(n*m+1, 0.0);
		cur[0] = 1.0;
		for(int i=0;i<n;i++){
			vector<double> next(n*m+1, 0.0);
			for(int j=0;j+m<=n*m;j++)
				for(int l=1;l<=m;l++)
					next[j+l] += cur[j]/m;
			cur = next;
		}
		double ans = 0.0;
		for(int i=1;i<=n*m;i++)
			ans += cur[i]*max(1,i-k);
		printf("%.8lf\n", ans);
	}
}