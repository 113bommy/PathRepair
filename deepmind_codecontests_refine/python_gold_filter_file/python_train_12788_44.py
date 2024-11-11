a,b,c,d,e,f=map(int,input().split())

ans_wat = 0
ans_sug = 0
ans_rate = 0

for i in range(31):#Aの投入数
  for j in range(31):#Bの投入数
      wat=(i*a+j*b)*100
      if wat<=f and wat:
          psug = min(f-wat,wat//100*e)
          for k in range(psug//c+1):
              l = (psug-c*k)//d
              sug = k*c+l*d
              rate = 100*sug/(wat+sug)
              if ans_rate<=rate and rate<=e and wat+sug<=f:
                  ans_wat = wat
                  ans_sug = sug
                  ans_rate = rate

print(ans_wat+ans_sug,ans_sug)