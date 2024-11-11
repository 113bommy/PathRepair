N=int(input())
L=list()
for i in range(N):
  L.append(list(input())*2)
L=L*2
ans=0
for o in range((2*N)-1):
  a=0
  if o<N:
    i=0
    j=o
    omomi=N-j
  else:
    j=0
    i=o-N+1
    omomi=N-i
  for t in range(N):
    for q in range(t):
      if L[i+t][j+q]!=L[i+q][j+t]:
        a=1
        break
    if a==1:
      break
  if a==0:
    ans+=omomi
print(ans)