N,L=map(int,input().split())
a=list(range(L,N+L))
print(sum(a)-min(a,key=abs))