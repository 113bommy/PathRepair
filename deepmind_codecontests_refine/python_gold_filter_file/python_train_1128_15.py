n = input()
A = list(map(int, input().split()))
flags = [False] * 8
count = 0
for a in A:
  if a < 3200:
    flags[a // 400] = True
  else:
    count += 1
print(max(sum(flags), 1), sum(flags) + count)
