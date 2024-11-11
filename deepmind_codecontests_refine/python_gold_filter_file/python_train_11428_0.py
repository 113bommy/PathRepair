n,x,m=map(int,input().split())

yj=[x]
lps=0
for i in range(n):
  an=(yj[i]**2)%m
  if an in yj:
    lps=yj.index(an)
    break
  yj.append(an)

blp=yj[:lps]
lp=yj[lps:]
ans=sum(blp)+sum(lp)*((n-len(blp))//len(lp))+sum(lp[:(n-len(blp))%len(lp)])
print(ans)
