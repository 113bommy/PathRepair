#include<ios>
main(){for(int q,b,c,d,r,A,N;std::cin>>q>>b>>c>>d>>r,q;A?printf("%d %d\n",A,N):printf("NA\n"))for(A=0;r;r--){N=(b-r*c)/d;if(b>=r*c&&N+r>=q){A=r;r=1;}}}