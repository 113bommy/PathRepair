n = int(input())
l = list(map(int,input().split()))
s,pref = 0,[]

for i in range(n):
    s+=l[i]
    if l[i]:
        pref.append(i)

if s==1:
    print(-1)
    exit()

divs = [s]
for i in range(2,int(s**0.5)+1):
    if s%i==0:
        divs.extend([i,s//i])

ans,value = 10**18,-3
for i in divs:
    cnt=0
    for j in range(0,s,i):
        mid = (i+2*j-1)//2
        for k in range(j,j+i):
            cnt+=abs(pref[k]-pref[mid])
    ans = min(ans,cnt)
print(ans)