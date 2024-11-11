def solve():
  n = int(input())
  a = list(map(int, input().split()))
  odd, even= [], []
  for i in range(2 * n):
    if a[i] % 2 == 1:
      odd.append(i + 1)
    else:
      even.append(i + 1)
  
  if len(odd) % 2 == 0 and len(even) % 2 == 0:
    if len(odd) > 0:
      odd.pop()
    elif len(even) > 0:
      even.pop()

  for i in range(0, len(odd) - 1, 2):
    print(odd[i], odd[i + 1])
  for i in range(0, len(even) - 1, 2):
    print(even[i], even[i + 1])

t = int(input())
for _ in range(t):
  solve()