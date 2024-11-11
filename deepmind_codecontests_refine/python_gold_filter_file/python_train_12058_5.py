n=int(input())
x=[input() for _ in range(n)]
ans='Yes'
if len(x)==len(set(x)):
  for i in range(n-1):
    if x[i][-1]!=x[i+1][0]:
      ans='No'
      break
else:
  ans='No'
print(ans)
