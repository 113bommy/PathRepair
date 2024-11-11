T = int(input())

"""
[1 1 2 5]

x = 3

"""
def check_possible(arr, x):
  return arr[-1] >= x

for t in range(T):
  n, x = [int(c) for c in (input()).split(' ')]
  a = [int(c) for c in (input()).split(' ')]
  a.sort()
  if not check_possible(a, x):
    print(0)
    continue

  bound = -1
  for i in range(1, n):
    if a[i-1] < x <= a[i]:
      bound = i - 1
      break
  # bound - where poor starts
  rich_count = n-bound-1
  available_money = sum(a[bound+1:]) - x * rich_count
  while bound >=0 and available_money > 0:
    m = min(available_money, x - a[bound])
    available_money -= m
    a[bound] += m
    if a[bound] == x:
      rich_count += 1
      bound -= 1
    else:
      break
  print(rich_count)
