n,a,b=list(map(int,input().split()))
c=[]
for i in range(1,n):
    if a//i>0 and b//(n-i)>0:
        c.append(min(a//i,b//(n-i)))
print(max(c))