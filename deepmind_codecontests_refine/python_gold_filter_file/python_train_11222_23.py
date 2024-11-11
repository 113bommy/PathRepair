n=int(input())
l=list(map(int,input().split()))
cnt=0
t=0
for i in range(n-1):
  if(l[i]>=l[i+1]):
    cnt+=1
  else:
    t=max(cnt,t)
    cnt=0
t=max(cnt,t)
print(t)