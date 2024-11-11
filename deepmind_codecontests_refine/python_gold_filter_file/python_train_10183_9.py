n, k = map(int, input().split())
TD = [[] for i in range(n)]
for i in range(n):
  TD[i] = list(map(int, input().split()))
  
TD.sort(key = lambda x:x[1], reverse = True)

ans = 0
huku = []
su = set([])

for i, j in TD[:k]:
  ans += j
  if i in su:
    huku.append([i,j])
  su.add(i)
ans += len(su)**2
huku.sort(key = lambda x:x[1], reverse = True)

ansl = []
ansl.append(ans)
for i,j in TD[k:]:
  if i in su:
    continue
  elif huku == []:
    break
  else:
    temp = ansl[-1] + j - huku.pop()[1] + (len(su)+1)**2 -len(su)**2
    su.add(i)
    ansl.append(temp)

print(max(ansl))
