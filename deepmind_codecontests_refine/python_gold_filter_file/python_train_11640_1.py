input()
mass = [int(s) for s in input().split()]
max = 0
result = ""

for n in mass:
  if max - n > 1:
    print("No")
    exit()
  if max < n:
    max = n

print("Yes")