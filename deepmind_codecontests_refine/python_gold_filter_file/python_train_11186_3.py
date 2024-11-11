from sys import stdin, setrecursionlimit

setrecursionlimit(200000)

n,k = [int(x) for x in stdin.readline().split()]

tree = {}

for x in range(n):
  s = stdin.readline().strip()

  cur = tree
  
  for x in s:
    if not x in cur:
      cur[x] = {}

    cur = cur[x]

def forced(tree):
  if not tree:
    return (False,True)
  else:
    win = False
    lose = False
    for x in tree:
      a,b = forced(tree[x])
      if not a:
        win = True
      if not b:
        lose = True
    return (win,lose)

a,b = forced(tree)

if a == 0:
  print('Second')
elif a == 1 and b == 1:
  print('First')
else:
  if k%2 == 0:
    print('Second')
  else:
    print('First')
