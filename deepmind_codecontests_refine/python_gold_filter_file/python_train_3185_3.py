a,b=input().split(' ')
a=int(a)
b=int(b)
n=0
while b>=a:
    a=a*3
    b=b*2
    n+=1
print(n)