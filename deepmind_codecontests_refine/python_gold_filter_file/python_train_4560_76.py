n,k = map(int,input().split())
a = list(map(int,input().split()))
f = list(map(int,input().split()))
a.sort()
f.sort(reverse = True)
def ok(p):
  result = 0
  for i in range(n):
    result += max(a[i]-p//f[i],0)
  if result <= k:
    return True
  return False

L = 0
U = a[-1]*f[0]
while U-L >= 1:
  M = (U+L)//2
  if ok(M):
    U = M
  else:
    L = M+1
    
print(U)
