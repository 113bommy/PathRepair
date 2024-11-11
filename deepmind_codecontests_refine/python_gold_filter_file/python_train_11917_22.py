a=int(input())
b=c=k=int(0)
while a>=b+c+1:
    c=c+1
    b=b+c
    a=a-b
    k=k+1
print(k)