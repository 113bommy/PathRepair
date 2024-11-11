N,M = map(int,input().split())
AC = 0
WA = 0
lis = [0] * N
for i in range(M):
  a,b = input().split()
  if lis[int(a)-1] < 0:
    pass
  elif b == 'AC':
    WA += lis[int(a)-1]
    AC += 1
    lis[int(a)-1] = -1
  else:
    lis[int(a)-1] += 1
print(AC, WA)
