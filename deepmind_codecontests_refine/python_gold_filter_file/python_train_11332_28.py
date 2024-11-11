n, m = map(int, input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]
ans = "Yes"
for i in a:
  for j in b:
    if j not in i:
      ans = "No"
print(ans)
