n = int(input())
A = list(map(int, input().split()))
q = int(input())
m = list(map(int, input().split()))

def solve(i, m):
  if m == 0:
    return True
  if i >= n :
    return False
  res = solve(i + 1, m) or solve(i + 1, m - A[i])
  return res

for tmp_m in m:
  if sum(A) < tmp_m:
    print('no')
  elif solve(0, tmp_m):
    print('yes')
  else:
    print('no')