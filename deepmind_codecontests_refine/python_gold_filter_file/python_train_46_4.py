
n=int(input())
a=list(map(int,input().split(" ")))
b=list(map(int,input().split(" ")))
c=list(map(int,input().split(" ")))

a.sort()
b.sort()
c.sort()
x=a[len(a)-1]
y=b[len(b)-1]
for i in range(0,len(a)-1):
    if a[i]!=b[i]:
        x=a[i]
        break
    
for i in range(0,len(b)-1):
    if b[i]!=c[i]:
        y=b[i]
        break
    
print(x)
print(y)