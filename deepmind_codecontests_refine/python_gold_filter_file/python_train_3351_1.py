I=input
for i in range(int(I())):
   a=I()
   b=I()
   n=len(a)
   c="NO"
   for i in range(n):
      if a[i] in b:
         c="YES"
         break
   print(c)
      