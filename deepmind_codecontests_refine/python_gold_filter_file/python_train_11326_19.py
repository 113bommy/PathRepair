h,w,a,b = map(int,input().split())
for i in range(b):
  s = '0'*a + '1'*(w-a)
  print(s)
for i in range(h-b):
  s = '1'*a + '0'*(w-a)
  print(s)