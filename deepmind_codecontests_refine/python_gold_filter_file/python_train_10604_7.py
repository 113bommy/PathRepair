n = input()
ans = 0
a = "CODEFESTIVAL2016"
for i, j in zip(n, a):
  if i != j:
    ans += 1
print(ans)
  