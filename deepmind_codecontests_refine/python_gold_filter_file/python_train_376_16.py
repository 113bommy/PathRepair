a=int(input())
b=int(input())
x=abs(b-a)
y=x//2
if x==1:
    print("1")
elif x%2==0:
    print(y*(y+1))
else:
    print((y+1)**2)