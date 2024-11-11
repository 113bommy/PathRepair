N, P = map(int,input().split())

def calc(n):
  num = {}
  e, i = 0, 2
  while i**2 <= n:
    while n%i == 0:
      n //= i
      e += 1
    if(e > 0):
      num[i] = e
    i += 1
    e = 0
  return num

if(N == 1):
  print(P)
  exit()
elif(P == 1):
  print(1)
  exit()
else:
  cnt = 1
  for k, v in calc(P).items():
    if(v >= N):
      cnt *= k ** (v//N)
  print(cnt)