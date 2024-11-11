n=int(input())
n-=1
f=0
ss=int(n**0.5)
ss+=1
for i in range(1,ss):
    if n%i==0:
        x=i
        a=n//x
        a=n-x-1
        y=a//2
        a=a/2
        if a==y and y>0:
            f=1
            break
if f:
    print(x,y)
else:
    print("NO")