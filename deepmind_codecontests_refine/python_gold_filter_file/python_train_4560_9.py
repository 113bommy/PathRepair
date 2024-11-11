(_,K),*T=[map(int,t.split())for t in open(0)]
A,B=map(sorted,T)
m,M,i=0,2**40,1
exec("i,M,m=((i+m)//2,i,m) if -sum(min(0,i-a*b)//b for a,b in zip(A,B[::-1]))<=K else((i+M)//2,M,i);"*41)
print(M)