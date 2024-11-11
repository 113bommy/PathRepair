n=int(input())
p=int(input())
a=1
for i in range(1,n):
    b=int(input())
    if(b!=p):
        a=a+1
    p=b
print(a)