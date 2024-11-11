a,b=map(int,input().split())
z=list(map(int,input().split()))
d={}
k=list(set(z));m=min(k)
for i in range(m,m+b+1):
    if i in k:k.remove(i)
if k:print("NO")
else:
    print("YES")
    k=[*range(1,b+1)]
    for i in z:print('1 '*m+' '.join(map(str,k[:i-m])))