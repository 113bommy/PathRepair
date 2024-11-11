N = int(input())

if N == 2:
  print(1)
  exit()

S = set([N-1])
lst = [N]
i = 2
while i*i <= N-1:
  if (N-1) % i == 0:
    S.add(i)
    S.add((N-1)//i)
  i += 1  
  
i = 2
while i*i < N:
  if N % i == 0:
    lst.append(i)
    lst.append(N//i)
  i += 1
    
if i*i == N:
  lst.append(i)
  
lst.sort()

for l in lst:
  if l in S:
    continue
  _N = N
  while _N % l == 0:
    _N //= l
  if _N % l == 1:
    S.add(l)
    
print(len(S))