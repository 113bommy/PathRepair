a,b,k=map(int,input().split())
c=max(a-k,0)
k-=a-c
d=max(b-k,0)
print(c,d)
