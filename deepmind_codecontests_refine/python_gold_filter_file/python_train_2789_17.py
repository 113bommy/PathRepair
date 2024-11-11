n = int(input())
arr = [int(x) for x in input().split()]
f = sum(arr)
s = 0
for i in arr:
  s += i * (f-i)

print(s // 2)
