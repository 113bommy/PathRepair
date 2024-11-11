a,b,k=map(int,input().split())
if k>=a:
    b=b-(k-a)
    a=0
else:
    a=a-k
print(a,max(b,0))