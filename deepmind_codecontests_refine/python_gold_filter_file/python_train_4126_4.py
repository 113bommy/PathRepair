
def summa(g):
  g = str(g)
  summ = 0
  for gg in g:
  	summ += int(gg)
  return summ
n = int(input())
arr = []
s = len(str(n))
up = 9*s
i = n-10000
if i < 0:
  i = 1
while summa(i) < up and i < n:
  if i + summa(i) == n:
    arr.append(i)
  i += 1
if len(arr) == 0:
  print(0)
else:
  print(len(arr))
  for i in range(len(arr)):
    print(arr[i])
  