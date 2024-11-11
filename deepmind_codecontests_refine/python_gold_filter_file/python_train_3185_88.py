a,b=input().split()
a=int(a)
b=int(b)
k=0
while a<=b:
    a*=3
    b*=2
    k+=1
print(k)