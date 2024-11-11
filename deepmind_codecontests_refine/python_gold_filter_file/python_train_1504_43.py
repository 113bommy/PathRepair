n = int(input())
s = []
for i in range(n):
   s.append(input())

r = 2*1000*1000*1000
l = -r

s = [x.split(' ') for x in s]
for i in s:
   st = i[0]
   c = int(i[1])
   ans = i[2]
   if ans == 'N':
      if st == '>': st = '<='
      elif st == '>=': st = '<'
      elif st == '<' : st = '>='
      else: st = '>'

   if st == '>': l = max(l, c+1)
   elif st == '>=': l = max(l, c)
   elif st == '<' : r = min(r, c-1)
   else: r = min(r,c)

if l > r:
   print('Impossible')
else:
   print((r-l)//2+l)