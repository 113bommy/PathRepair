n=int(input())
w=list(map(int,input().split()))
s=sum(w)
cnt=0
t=10**5
for i in range(n):
  cnt+=w[i]
  t=min(t,abs(s-2*cnt))
print(t)