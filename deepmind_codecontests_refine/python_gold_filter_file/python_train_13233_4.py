n = int(input())
l = list(map(int, input().split()))
nums = set()
ans = 0

copy = l[:]
copy.sort()

sm = sum(copy)

for i in range(n-1):
  if sm-copy[i]-copy[-1] == copy[-1]:
    nums.add(copy[i])
    ans += 1

if sm-copy[-1]-copy[-2] == copy[-2]:
  nums.add(copy[-1])
  ans += 1

print(ans)
for i in nums:
  for j in range(len(l)):
    if i == l[j]:
      print(j+1, end=' ')
