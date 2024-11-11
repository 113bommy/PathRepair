def Rd(f = int):
  return [f(x) for x in input().split()]

def PrintFloats(arr):
  return ' '.join('{:.10f}'.format(x) for x in arr)

###

n = int(input())
s = input()

op = s.count('(')
cl = s.count(')')

def Solve(s):
  bal = 0
  end = n-1  
  for bwd in range(n-1, -1, -1):
    if s[bwd] == '(': bal += 1
    else: bal -= 1
    end = bwd
    if bal > 0: break

  bal = 0
  ans = 0
  for fwd in range(n):
    if s[fwd] == '(':
      if bal > 0 and fwd >= end: ans += 1
      bal += 1
    else: bal -= 1
    if bal < 0: break    
  return ans

if op == cl + 2:
  print(Solve(s))
elif cl == op + 2:
  s2 = s.replace('(', 'x').replace(')', '(').replace('x', ')')
  print(Solve(s2[::-1]))
else:
  print(0)
