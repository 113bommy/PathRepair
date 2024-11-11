n = int(input())
st = [list(input().split()) for nesya in range(n)]
x = input()
c = 0
for a in st:
  if x == a[0]:
    c = 0
  else:
    c += int(a[1])
print(c)