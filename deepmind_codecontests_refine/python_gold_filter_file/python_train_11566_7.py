n=int(input())
m=[]
c=0
l=list(map(int,input().split()))
for i in range(n-1):
        
    if l[i]>=l[i+1]:
        c=c+1
        m.append(l[i])
print(c+1)
b=len(m)
for i in range(b):
    print(m[i],end=" ")
print(l[n-1])