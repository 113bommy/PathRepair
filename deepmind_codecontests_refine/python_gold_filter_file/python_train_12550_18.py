n,c=map(int,input().split())
l=list(map(int,input().split()))
k=1
for i in range(n-1):
    if (l[i+1]-l[i])>c:
        k=1
    else:
        k=k+1
print(k)
    
    
