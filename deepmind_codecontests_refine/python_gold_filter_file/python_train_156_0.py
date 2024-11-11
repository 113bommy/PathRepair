n=list(map(int,input().split()))
d=list(map(int,input().split()))
k=n[1]
m=n[0]
x=0
for i in range (1,m+1):
    h=i
    x+=i
    if k<=x:
        break
l=k-x+h-1
print (d[l])