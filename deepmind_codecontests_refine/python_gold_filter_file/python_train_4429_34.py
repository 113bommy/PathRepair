
a,b=map(int, input().split())
c=list(map(int, input().split()))
d=list(map(int, input().split()))
cnt=0
e=0
cnd=0
f=0
for i in range(a):
  cnt+=max(0,c[i]-b*(d[i]+e))
  e+=d[i]
i+=1

for j in range(a):
  cnd+=max(0,c[a-1-j]-b*(d[a-1-j]+f))
  f+=d[a-1-j]
j+=1

if cnt>cnd:
  print("Limak")
elif cnd>cnt:
  print("Radewoosh")
else:
  print("Tie")