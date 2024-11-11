n,k=map(int,input().split())
S=input()

cnt=0
for i in range(1,n):
  if S[i-1]==S[i]:
    cnt+=1
print(min(n-1,cnt+2*k))