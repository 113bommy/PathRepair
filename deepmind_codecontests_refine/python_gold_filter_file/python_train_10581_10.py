n,m=input().split(" ")
n=int(n)
m=int(m)
p=100000
for i in range(n):
    a,b=input().split(" ")
    a=int(a)
    b=int(b)
    if a/b<p:
        p=a/b
print(p*m)