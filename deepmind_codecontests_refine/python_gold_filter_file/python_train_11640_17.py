N=int(input())
H=list(map(int,input().split()))
p,a=True,0
for h in H:
  if h>a:
    a=h-1
  elif a>h:
    p=False
    break
print("Yes" if p else "No")