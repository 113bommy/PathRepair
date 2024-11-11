q=int(input())
a=list(map(int,input().split()))
z=1
b=len(a)
c=a[0]
d=a[-1]
for i in range (b-1,0,-1):
    if a[i]!=c:
        z=max(z,i)
        break
for i in range (0,b-1,1):
    if a[i]!=d:
        z=max(z,b-i-1)
        break

print(z)
