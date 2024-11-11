N = input()
ans = 0
for i in range(1,4):
  p = "R"*i
  if p in N:
    ans = i
print(ans)