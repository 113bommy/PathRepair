n=int(input())
l=list(map(int,input().split()))
cnt=[0]*(10**6+100)
for i in l:
  cnt[i]+=1
s=0
ans=0
for i in cnt:
 s+=i
 ans+=s%2
 s//=2
print(ans)
