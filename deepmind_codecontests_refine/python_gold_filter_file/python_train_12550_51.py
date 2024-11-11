n,c=map(int,input().split())
l=list(map(int,input().split()))
k=0
for i in range(n-1):
    if l[i+1]-l[i]>c:
        k=0
    else:
        k=k+1
if k==0 :
    print(1)
else:
    print(k+1)
        
