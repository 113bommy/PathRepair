def NOD(a, b):
  if a == 0:
    return b
  elif b == 0:
    return a
  elif a > b:
    return NOD(a % b, b)
  return NOD(a, b % a)

k = int(input())
for i in range(k):
  a, b = map(int, input().split())
  temp = NOD(a, b)
  if(temp == 1):
    print("Finite")
  else:
    print("infinite")