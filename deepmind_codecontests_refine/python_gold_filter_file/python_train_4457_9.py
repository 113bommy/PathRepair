n, k = map(int, input().split())
dp = {}

dp[(0, 0, 0)] = 1

def perm(i, j, k):
  if (i, j, k) in dp:
    return dp[(i, j, k)]
  
  if i == 0 and (j is not 0 or k is not 0):
    return 0
  
  if i < 0 or j < 0 or k < 0 or i < j:
    return 0
  
  dp[(i, j, k)] = ((j+j+1)*perm(i-1, j, k-2*j)\
                + (j+1)*(j+1)*perm(i-1, j+1, k-2*j)\
                +  1*perm(i-1, j-1, k-2*j))%(10**9+7)
  return dp[(i, j, k)]

print(perm(n, 0, k))