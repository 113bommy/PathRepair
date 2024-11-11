a=int(input())
b=int(input())
x=abs(a-b)
y=x//2
if x%2==0:
    c=y*(y+1)
else:
    c=((y*(y+1))//2)+(((y+1)*(y+2))//2)
print(c)