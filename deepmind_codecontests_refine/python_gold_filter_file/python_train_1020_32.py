n=int(input())
 
def dfs(s):
  if int(s)>n:
    return 0
  cnt=1 if all(s.count(i)>0 for i in '753') else 0
  for j in '753':
    cnt+=dfs(s+j)
  return cnt
  
print(dfs('0'))