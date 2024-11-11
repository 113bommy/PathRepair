n=int(input())
l=input().split()
for i in range(n):
    l[i]=int(l[i])
k=l.index(min(l))
if(k==0 and l[-1]==l[k]):
    i=n-1
    while(i>-1 and l[i]==l[k]):
        i-=1
    k=i+1
j=k
i=j+1
s=1
while(s<n):
    if(i==n):
        i=i%n
    if(j==n):
        j=j%n
    if(l[j]<=l[i]):
        s+=1
        j+=1
        i+=1
    else:
        break

if(s==n):
    if(k==0):
        print(0)
    else:
        print(n-k)
else:
    print(-1)
