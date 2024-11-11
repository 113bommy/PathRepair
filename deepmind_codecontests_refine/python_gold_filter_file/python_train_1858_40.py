from collections import Counter
def check():
  H, W = map(int, input().split())
  S = [input() for _ in range(H)]
  s = ''.join(S)
  c = Counter(s)
  d = Counter(c.values())
  two = 0
  one = 0
  for k,v in d.items():
    if k%4==2 or k%4==3:
      two += 2*v
    if k%2==1:
      one += v
  if H%2==0 and W%2==0:
    if two>0 or one>0:
        return 'No'
  elif H%2==1 and W%2==1:
    if two>(H+W-2) or one>1:
      return 'No'
  elif H%2==1:
    if two>W or one>0:
      return 'No'
  elif W%2==1:
    if two>H or one>0:
      return 'No'
  return 'Yes'
print(check())