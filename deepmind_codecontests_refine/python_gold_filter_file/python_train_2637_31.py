n=int(input())
l=list(map(int,input().split()))
x=l.count(4)
y=l.count(3)
z=l.count(2)
t=l.count(1)
if y>=t:
    print(x+y+(z+1)//2)
else:
    print(x+y+(z+1)//2+(t-y-(z%2)*2+3)//4)