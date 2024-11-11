a,b,k=map(int,input().split())
a2=max(0,a-k)
b=max(0,b-(k-(a-a2)))

print(a2,b)
