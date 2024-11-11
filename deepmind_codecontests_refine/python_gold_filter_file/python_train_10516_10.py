s=[]
for p in input().split():
 if p in "+-*":
  b=s.pop()
  a=s.pop()
  s.append(str(eval(a+p+b)))
 else:
  s.append(p)
print(*s)
