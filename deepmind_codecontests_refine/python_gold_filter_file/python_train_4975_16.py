n=int(input())
ans=[0]*n
three=n//3
two=(n-three)//2
one=n-three-two
t=[[]for _ in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  a-=1
  b-=1
  t[a].append(b)
  t[b].append(a)
th=[]
Q=[0]
visited={0}
ma=0
thi=-1
while Q:
  th.append(Q)
  if len(Q)>ma:
    ma=len(Q)
    thi=len(th)-1
  P=[]
  for j in Q:
    for i in t[j]:
      if i not in visited:
        P.append(i)
        visited.add(i)
  Q=P
odd=even=0
for i in range(len(th)):
  if i%2==1:odd+=len(th[i])
  else:even+=len(th[i])
if odd>one+three:
  flag="error"
  d=0
elif even>one+three:
  flag="error"
  d=1
else:
  flag="normal"

if flag=="error":
  sudenideta=set()
  num=3
  for i in range(d,len(th),2):
    for j in th[i]:
      ans[j]=num
      sudenideta.add(num)
      num+=3
  num=1
  for i in range(d^1,len(th),2):
    for j in th[i]:
      while num in sudenideta:num+=1
      ans[j]=num
      sudenideta.add(num)
      num+=1
else:
  odd_num=2
  even_num=1
  three_num=3
  for i in range(len(th)):
    for j in th[i]:
      if i%2==1:
        if odd_num>n:
          ans[j]=three_num
          three_num+=3
        else:
          ans[j]=odd_num
          odd_num+=3
      else:
        if even_num>n:
          ans[j]=three_num
          three_num+=3
        else:
          ans[j]=even_num
          even_num+=3
print(*ans)