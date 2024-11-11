n,x=map(int,input().split())
c=0
for _ in range(n):
   s=input().split(" ")
   if s[0]=='+':
      x=x+int(s[1])
   else:
      if x>=int(s[1]):
         x=x-int(s[1])
      else:
         c=c+1
print(x,c)