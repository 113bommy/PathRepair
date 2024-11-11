a,b=input().split()
a=int(a)
b=int(b)
for i in reversed(range(b)):
    if a%i==0:
        print(int(((a*b)/i)+i))
        break
