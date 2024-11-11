N = int(input())
L = []
for i in range(N):
  L.append((int(input()),'a'))
for i in range(N):
  L.append((int(input()),'b'))
L.sort()
res = 1
cc = 0
nowcol = None
mo = 1000000007
for i in range(2*N):
  if cc == 0:
    nowcol=L[i][1]
  if nowcol == L[i][1]:
    cc += 1
  else:
    res *= cc
    res %= mo
    cc -= 1
print(res)
