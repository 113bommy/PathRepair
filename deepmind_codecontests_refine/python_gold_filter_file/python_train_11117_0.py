n,m=map(int,input().split())
ac=[0]*n
wa=[0]*n
for i in range(m):
  p,s=map(str,input().split())
  p=int(p)-1
  if ac[p]==0:
    if s=='AC':
      ac[p]=1
    else:
      wa[p]+=1

w=0
for i in range (n):
  w+=ac[i]*wa[i]
print(sum(ac),w)