N, K = map(int, input().split())
As = list(map(int, input().split()))
Fs = list(map(int, input().split()))
As.sort()
Fs.sort(reverse=True)
def check(x):
  k = 0
  for i in range(N):
    k += max(0, As[i]-x//Fs[i])
  return k <= K
a = 0
b = As[-1]*Fs[0]
while a < b:
  i = (a + b)//2
  if check(i):
    b = i
  else:
    if a == i:
      break
    a = i
r = b
print(r)
