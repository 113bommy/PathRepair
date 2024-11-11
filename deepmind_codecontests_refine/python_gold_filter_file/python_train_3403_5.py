from sys import exit

n=int(input())
a=list(map(int,input().strip().split()))
b=set(a)
for i in range(n):
    for j in range(0,31):
        if a[i]-2**j in b and a[i]+2**j in b:
            print(3)
            print(a[i],a[i]-2**j,a[i]+2**j)
            exit()
for i in range(n):
    for j in range(0,31):
        if a[i]-2**j in b:
            print(2)
            print(a[i],a[i]-2**j)
            exit()
        else:
            continue
print(1)
print(a[0])