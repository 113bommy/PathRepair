r,g,b = map(int,input().split())
def f1(r):
  if r%2 == 0:
    x=3*(r/2-1)
  else:
    x=3*int(r//2)
  return x
print(int(max(f1(r),f1(g)+1,f1(b)+2) + 30))

