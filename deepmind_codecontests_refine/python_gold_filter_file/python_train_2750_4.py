n = int(input())
l = list(map(int, input().split()))
x = {}

for i in range(n):
  if not int(l[i]) in x:
    x.update({ int(l[i]) : 1})
  else:
    x.update({ int(l[i]) : int(x.get(l[i])) + 1})

maxNum = 0
for atsl in x:
  if x[atsl] > maxNum:
    maxNum = x[atsl]

print(maxNum, len(x))