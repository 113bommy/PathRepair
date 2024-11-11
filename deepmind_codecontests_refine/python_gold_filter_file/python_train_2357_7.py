import sys

#needed: 4 a, 2b
n = int(sys.stdin.readline().strip())
am = int(sys.stdin.readline().strip())
bm = int(sys.stdin.readline().strip())

def recurse(a, b):
  global n
  #print("foo", a, b)
  pairs = set()
  
  if(a <= 0 and b <= 0):
    return 0;
    
  for i in range(0, a + 1):
    for j in range(0, b + 1):
      pairs.add((i, j))
      
  woods = 1
  answer = float("inf")
  for (i, j) in pairs:
    if(n >= (am * i + bm * j) and (am * i + bm * j) is not 0):
      rec = recurse(a - i, b - j)
      #print(n, (am * i + bm * j), rec)
      answer = min(answer, rec)
  
  return woods + answer

print(recurse(4, 2))
