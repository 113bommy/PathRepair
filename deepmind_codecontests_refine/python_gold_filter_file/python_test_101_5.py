import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_list_strings(): return list(map(str, sys.stdin.readline().strip().split()))


# Output for list
# sys.stdout.write(" ".join(map(str, final)) + "\n")

# Output for int or str
# sys.stdout.write(str(best) + "\n")



def solve(n, arr, s):
  r = []
  b = []

  for i, ele in enumerate(s):
    if ele == 'R':
      if arr[i] > n:
        print("NO")
        return
      
      if arr[i] <= 0:
        arr[i] = 1

      r.append(arr[i])
    else:
      if arr[i] <= 0:
        print("NO")
        return
      
      if arr[i] > n:
        arr[i] = n

      b.append(arr[i])
  
  r.sort()
  b.sort()

  c = 1

  i = 0
  j = 0

  l1 = len(r)
  l2 = len(b)

  while i < l1 and j < l2:
    if c <= b[j]:
      j += 1
      c += 1
    elif r[i] <= c:
      i += 1
      c += 1
    else:
      print("NO")
      return
  
  while j < l2:
    if c <= b[j]:
      j += 1
      c += 1
    else:
      print("NO")
      return

  while i < l1:
    if r[i] <= c:
      i += 1
      c += 1
    else:
      print("NO")
      return

  print("YES")

















T = get_int()
while T:
  n = get_int()
  arr = get_list()
  s = get_string()
  solve(n, arr, s)
  T -= 1
