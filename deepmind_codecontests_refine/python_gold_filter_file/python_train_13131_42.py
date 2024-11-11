a=input()
b=input()

a=a.lower()
b=b.lower()

if a==b:
    print("0")
else:
     for i in range(len(a)):
         if a[i]<b[i]:
             print("-1")
             exit(0)
         elif a[i]>b[i]:
             print("1")
             exit(0)
        