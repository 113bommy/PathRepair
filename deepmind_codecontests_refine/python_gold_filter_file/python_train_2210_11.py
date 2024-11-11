n=int(input())
t=[0]*21
a=list(map(int,input().split()))
for i in range(n):
    t[a[i]+10]+=1
k=0
j=20
ans=0

while k<10 and j >10:
    ans+=t[k]*t[j]
    j-=1
    k+=1
if t[10]:
    ans+= (t[10]*(t[10]-1))//2

        
print(ans)


