n=int(input())
l=list(map(int,input().split()))
m=max(l)
s=sum(l)
s*=2
s+=n
s//=n
print(max(m,s))