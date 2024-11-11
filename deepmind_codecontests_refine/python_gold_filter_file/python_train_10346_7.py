n,k=map(int,input().split())
l=[]
for i in range(n):
    f,t=map(int,input().split())
    if (t>k):
        x=f-(t-k)
    else:
        x=f
    l.append(x)
print(max(l))