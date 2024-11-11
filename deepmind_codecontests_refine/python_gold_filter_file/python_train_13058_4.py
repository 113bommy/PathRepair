string=input().split()
n=int(string[0])
t=int(string[1])
c=int(string[2])
a=list(map(int,input().split()))
kol=0
for i in range(c):
    if a[i]>t: kol+=1
if kol==0: ans=1
else: ans=0
for i in range(c,n):
    if a[i-c]>t: kol-=1
    if a[i]>t: kol+=1
    if kol==0: ans+=1
    #print(i,kol)
print(ans)
