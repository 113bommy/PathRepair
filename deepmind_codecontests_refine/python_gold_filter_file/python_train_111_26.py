input()
numbers = [int(x) for x in input().split()]

opponent = sum(numbers)
k = max(numbers)
count = 0

for val in numbers:
  count = count + k - val

while count <= opponent:
  k = k + 1
  count = count + len(numbers)

print(k)