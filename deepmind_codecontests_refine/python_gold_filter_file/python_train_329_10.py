n, p, w, d = map(int, input().split(' '))

sol = -1

def lcm(a, b):
  return a * b

multiple = lcm(d, w)


add = 0
rest = p // multiple

if(rest >= 1):
  rest -= 1
  add = multiple

p = p % multiple + add
sol = [(multiple // w) * rest, 0]

min_sol = -1

if(p == 0):
  min_sol = sol
else:
  i = 0
  extraSol = -1

  while(i * w) <= p:
    rest = p - i * w
    
    if(rest % d) == 0:
      if extraSol == -1:
        extraSol = [i, rest // d]
      else:
        extraSol = [i, rest // d]
    i += 1

  if(extraSol != -1):
    min_sol = [sol[0] + extraSol[0], sol[1] + extraSol[1]] 

if(min_sol == -1):
  print(-1)
else:
  w, d = min_sol
  l = n - d - w

  if(l >= 0):
    print(w, d, l)
  else:
    print(-1)