N,L=map(int,input().split())
souwa=(L-1)*N+N*(N+1)//2
print(souwa-L if L>=0 else souwa if -N+1<=L<0 else souwa-(L+N-1) )