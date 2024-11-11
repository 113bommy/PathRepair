n=int(input())
t=list(map(int,input().split()))
v=list(map(int,input().split()))
T=[0,t[0]]
for i in range(n-1):
  T.append(T[i+1]+t[i+1])
L=[[] for i in range(2*sum(t))]
for i in range(2*sum(t)):
  for j in range(n):
    if T[j]<=i/2<=T[j+1]:
      x=v[j]
    elif i/2<T[j]:
      x=v[j]+abs(i/2-T[j])
    else:
      x=v[j]+abs(i/2-T[j+1])
    L[i].append(x)
for i in range(2*sum(t)):
  L[i].append(i/2)
  L[i].append(sum(t)-i/2)

for i in range(2*sum(t)):
  L[i]=min(L[i])
ans=0
for i in range(2*sum(t)):
  if i==2*sum(t)-1:
    ans+=L[i]*0.25
  else:
    ans+=(L[i]+L[i+1])*0.25
print(ans)