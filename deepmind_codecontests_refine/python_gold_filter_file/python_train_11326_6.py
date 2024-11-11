h, w, a, b = map(int, input().split())
if b > h / 2:
  if a > w / 2:
    print('No')
    
for i in range(h):
  if i < b:
    print('0'*a + '1'*(w-a))
  else:
    print('1'*a + '0'*(w-a))