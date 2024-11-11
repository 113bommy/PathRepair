def f(a,b,c):
  if a%2+b%2+c%2>0:
    return 0
  if a==b==c:
    return -1
  return f((b+c)//2,(c+a)//2,(a+b)//2)+1

a,b,c=map(int,input().split())
print(f(a,b,c))
