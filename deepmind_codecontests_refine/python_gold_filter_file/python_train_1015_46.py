n,k=map(int,input().split())
a=[int(input()) for _ in range(n)]
l=[[] for i in range(n)]

l[0].append(a[0])
ans=0
for ai in a[1:]:
  for i in reversed(range(ans+1)): # if can a_i put backword, add l[i+1]. because of maximum length answer 
    for li in l[i]:
      if -k<=(li-ai)<=k:
        ans=max(ans,i+1)
        l[i+1].append(ai)
        break
    else:
      continue
    break
  else:
    l[0].append(ai)

print(ans+1)