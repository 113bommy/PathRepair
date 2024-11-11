n=int(input())
s=input()
if s.count('0')!=s.count('1'):
  print(1)
  print(s)
else:
  print(2)
  print(s[0:-1]+' '+s[-1])