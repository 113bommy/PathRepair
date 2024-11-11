s = input()
ans = 0
for i in range(1,4):
  r = "R"*i
  if r in s:
    ans = i

print(ans)