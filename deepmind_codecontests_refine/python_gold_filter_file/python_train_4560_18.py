N,K=map(int,input().split())
X=[(b,a*b)for a,b in zip(sorted(list(map(int,input().split()))),sorted(list(map(int,input().split())))[::-1])]
m,M,i=0,2**40,1
exec("i,M,m=((i+m)//2,i,m) if -sum(min(0,i-c)//b for b, c in X)<=K else((i+M)//2,M,i);"*50)
print(M)