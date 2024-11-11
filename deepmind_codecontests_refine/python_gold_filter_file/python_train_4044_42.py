n = int(input())
l = [2,1]
for i in range(n-1):
  l.append(l[-1]+l[-2])
print(l[-1])