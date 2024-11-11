n=int(input())
x=input()
val=int(x,2)

cnt=x.count("1")
p_cnt=cnt+1
m_cnt=cnt-1
p_amari,m_amari=0,0

p_amari=val%(cnt+1)
if cnt-1!=0:
  m_amari=val%(cnt-1)
else:
  m_amari=0

for i in range(n):
  ans=0
  if x[i]=="0":
    amari=p_amari+pow(2,n-i-1,p_cnt)
    amari%=p_cnt
  elif x[i]=="1":
    if cnt-1==0:
      print(0)
      continue
    amari=m_amari-pow(2,n-i-1,m_cnt)
    amari%=m_cnt
  ans+=1
  while amari!=0:
    amari%=bin(amari).count("1")
    ans+=1
  print(ans)
