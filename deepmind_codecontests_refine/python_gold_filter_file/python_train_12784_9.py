n,k=map(int,input().split())
s=0
l=list(map(int,input().split()))
c=1
for i in range(n):
    s+=l[i]
    if(k<s):
        break
    c+=1
print(c)
