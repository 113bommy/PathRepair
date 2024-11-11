
a,b,k=map(int,input().split())

a1=max(a-k,0)
k=max(k-a,0)
b=max(b-k,0)
print(a1,b)
