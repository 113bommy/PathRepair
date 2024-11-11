a,b,c,d=map(int,input().split())
e=[a,b,c,d]
e.sort(reverse = True)
tam=0
f=[]
for i in range(1,len(e)):
      tam = e[0] - e[i]
      f.append(tam)
for i in range(0,len(f)):
      print(f[i],end=' ')
            