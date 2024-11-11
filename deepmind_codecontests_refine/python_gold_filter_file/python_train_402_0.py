def f(e):
 a=list([*map(int,input().split())]for _ in range(int(e)))
 s,t=a[0]
 b={tuple(map(int,input().split()))for _ in range(int(input()))}
 for x,y in b:
  for u,v in a[1:]:
   if(x+u-s,y+v-t)not in b:break
  else:return print(x-s,y-t)
for e in iter(input,'0'):f(e)
