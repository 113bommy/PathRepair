a1=[]
a2=[]
n1=int(input())
n=0
for i in range(n1):
  a,b=map(int,input().split())
  h=list(map(int,input().split()))
  s=0
  if a>b or a==2:
      a1.append(-1)
      a2.append(a)
  else:
      for i in range(a):
          s=s+h[i]
      s=s*2
      a1.append(s)
      a2.append(a)
for i in range(n1):
    print(a1[i])
    if a1[i]!=-1:
        for i1 in range(a2[i]):
            c=i1+2
            if i1+2>a2[i]:
                c=(i1+2)%a2[i]
            print(i1+1," ",c)