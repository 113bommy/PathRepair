n=int(input())
a=input().split()
xor=0
ans=int(a[0])
for i in range(n):
    for j in range(i,n):
        ans=int(a[i])
        for k in range(i+1,j+1):
            ans=ans^int(a[k])
        if(ans>=xor):
            xor=ans
            
print(xor)