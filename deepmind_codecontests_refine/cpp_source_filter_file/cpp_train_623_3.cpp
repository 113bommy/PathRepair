#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

int *Lv;
int n, k;

bool cmp_Lv(const int i, const int j){ return Lv[i] < Lv[j]; }

bool cmp(const int i, const int j){
    if(Lv[i] != Lv[j]){ return Lv[i] < Lv[j]; }
    int L_i = (i + k >= n ? -1 : Lv[i + k]);
    int L_j = (j + k >= n ? -1 : Lv[j + k]);

    return L_i < L_j;
}

int main()
{
    int *A, *newLv;
    std::string T;
    std::cin >> T;
    n = T.size();

    A = new int [n + 1]; Lv = new int [n + 1]; newLv = new int [n + 1];

    int i;
    for(i = 0; i < n; i++){ A[i] = i; }
    for(i = 0; i < n; i++){ Lv[i] = T[i]; }
    std::sort(A, A + n, cmp_Lv);

    newLv[A[0]] = 0;
    for(i = 1; i < n; i++){
        newLv[A[i]] = newLv[A[i - 1]] + (Lv[A[i]] != Lv[A[i - 1]] ? 1 : 0);
    }
    for(i = 0; i < n; i++){ Lv[i] = newLv[i]; }

    k = 1;
    while(1){
        if(k > n) break;

        std::sort(A, A + n, cmp);
        newLv[A[0]] = 0;
        for(i = 1; i < n; i++){ newLv[A[i]] = newLv[A[i - 1]] + (cmp(A[i - 1], A[i]) ? 1 : 0); }
        for(i = 0; i < n; i++){ Lv[i] = newLv[i]; }

        if(Lv[A[n - 1]] == n - 1) break;
        k <<= 1;
    };

    delete [] Lv; delete [] newLv;

	std::string P;
    int q, left, right, mid, crit;
    bool exist;
    scanf("%d", &q);

    A[n] = n;

    while(q){
        cin >> P;
        left = 0, right = n, exist = false;
        while(left < right){

            if(n < P.size()){ exist = false; break; }

            mid = (left + right) / 2;
            crit = T.compare(A[mid], P.size(), P);

            if(crit > 0){ right = mid; }
            else if(crit < 0){ left = mid + 1; }
            else{ exist = true; break; }
        };
        if(T.compare(A[right], P.size(), P) == 0) exist = true;
        if(exist){ printf("1\n"); }else{ printf("0\n"); }
        q--;
    }
	delete [] A;
    return 0;
}