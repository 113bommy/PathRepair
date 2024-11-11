#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int N_MAX = 100000;
const int R_MAX = 50;
const int BigNumber = 1000000007;	

 struct squaence{
	int start,length, counter;
	
	squaence(){}
	squaence(int _start, int _end){
		start = _start;
		length = _end - _start + 1;
		counter = 0;
	}
};



int main(){
	int s[R_MAX], t[R_MAX], N, R;
	
	long long SigmaFactrial[N_MAX+1];
	SigmaFactrial[0] = 0;
	long long factrial = 1;
	for(int i=1; i<N_MAX+1; i++){
		SigmaFactrial[i] = (SigmaFactrial[i-1]+factrial)%BigNumber;
		factrial = (factrial*i)%BigNumber;	
	}

	while(true){
		cin >> N;
		if(N==0) break;
		cin >> R;	
		
		vector<int> st_vector(2*R);
		for(int r=0; r<R; r++){
			int tmp_s, tmp_t;
			cin >> tmp_s >> tmp_t;
			s[r] = tmp_s-1;
			t[r] = tmp_t-1;
			st_vector[2*r  ] = s[r];
			st_vector[2*r+1] = t[r];
		}
		sort(st_vector.begin(), st_vector.end());
		st_vector.erase(unique(st_vector.begin(), st_vector.end()), st_vector.end());
		const int st_vector_size = st_vector.size();
		
		vector<squaence> number;
		int n=0;
		for(int j=0; j<st_vector_size; j++){
			if(n <st_vector[j])number.push_back(squaence(n, st_vector[j]-1));
			n = st_vector[j];
			number.push_back(squaence(n, n));
			n++;
		}
		if(n<N)number.push_back(squaence(n, N-1));
			
		map<int,int> index_map;
		for(int i=0; i<st_vector_size; i++){
			int v = st_vector[i];
			auto it = find_if(number.begin(), number.end(), [v](squaence s){return s.start==v;});
			index_map[v] = distance(number.begin(), it) ;
		}

		for(int r=0; r<R; r++){
			int rs = index_map[s[r]];
			int rt = index_map[t[r]];

			int ns = number[rs].start;
			int nt = number[rt].start;
			int cs = number[rs].counter;
			int ct = number[rt].counter;
				
			if(ns<nt)	ct++;
			else		cs--;
			for(int i=rs+1; i<rt; i++){
				int ni = number[i].start;
				if(ni < nt){
					ct+=number[i].length;
					if(ns<ni) number[i].counter++;
				}
				if(ni < ns){
					cs-=number[i].length;
					if(nt<ni) number[i].counter--;
				}
			}

			number[rs].counter = cs;
			number[rt].counter = ct;
			swap(number[rs], number[rt]);
		}
	
		n=0;
		long long index = 0;
		const int number_size = number.size();
		for(int i=0; i<number_size; i++){
			const squaence* s = &number[number_size-1-i];
			if(s->counter != 0)index += s->counter * (SigmaFactrial[n+s->length] - SigmaFactrial[n]) % BigNumber;
			n += s->length;
		}
		
		while(index<0) index+=BigNumber;
		cout << index%BigNumber << endl;
	}
	return 0;
}