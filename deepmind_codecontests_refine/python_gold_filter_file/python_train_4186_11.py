def cal(s):
  n = len(s)
  for i in range(1, n+1):
    if s[-i] == '1':
      return (n-i+1)*2
  return n

q = int(input())
for run in range(q):
  n = int(input())
  s = input()
  print(max(cal(s), cal(s[::-1])))


