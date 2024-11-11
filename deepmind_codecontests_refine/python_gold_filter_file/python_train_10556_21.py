from sys import stdin, stdout
def stdinhack():
  for line in stdin: yield line
next_line = lambda: next(stdinhack()).split()
write = lambda x : stdout.write(x)

def solve ():
  x, y = map(int, next_line())
  if x>0 and y>0: print(0, x+y, x+y,0)
  if x<0 and y>0: print(x-y, 0, 0, -x+y)
  if x>0 and y<0: print(0, y-x, x-y, 0)
  if x<0 and y<0: print(x+y,0,0,x+y)
  return

if __name__ == '__main__':
  solve()

