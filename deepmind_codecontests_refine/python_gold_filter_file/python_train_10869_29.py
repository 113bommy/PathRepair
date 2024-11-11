n=int(input())
a=[int(i) for i in input().split()]
m=abs(a[0]-a[n-1])
pos1=0
pos2=n-1
i=1
while i<n:
    if abs(a[i]-a[i-1])<m:
        m=abs(a[i]-a[i-1])
        pos1=i-1
        pos2=i
    i+=1
print(pos1+1,pos2+1)