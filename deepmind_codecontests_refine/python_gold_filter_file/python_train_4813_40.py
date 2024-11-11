t=int(input())
for _ in range(t):
  a,b,c=map(int,input().split())
  ans=10**18
  cand=[]
  for ta in range(1,2*10**4+1):
    for n in range(1,2*10**4//ta+1):
      tmp=abs(ta-a)
      tb=n*ta
      tmp+=abs(tb-b)
      tc1=c+(tb-c%tb)
      tc2=c-c%tb
      if tc2>=tb:
        if abs(tc1-c)<=abs(tc2-c):
          tc=tc1
        else:
          tc=tc2
      else:
        tc=tc1
      tmp+=abs(tc-c)
      if tmp<ans:
        ans=tmp
        cand=[ta,tb,tc]
  print(ans)
  print(*cand)