s=input()
a='abcdefghijklmnopqrstuvwxyz'
r='zyxwvutsrqponmlkjihgfedcba'
if len(s)!=26:
  for i in a:
    if i not in s:
      s=s+i
      break
elif s==r:
  s=-1
else:
  for i in range(25,0,-1):
    if i==1:
      s=chr(ord(s[0])+1)
      break
    if s[i]>s[i-1]:
      l=sorted(s[i:])
      for j in l:
        if j>s[i-1]:
          m=j
          break
      s=s[:i-1]+m
      break
print(s)