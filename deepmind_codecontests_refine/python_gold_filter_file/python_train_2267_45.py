x,n=map(int,input().split())
p=list(map(int,input().split()))

m=100
a=x
for i in range(-101,201):
    if i not in p:
        z=abs(i-x)
        if m>z:
            m=z
            a=i

print(a)