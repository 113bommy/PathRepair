n=int(input())
a=[0 for i in range(101)]
a[1]=1
sides=4
for i in range(2,101):
    a[i]=a[i-1]+sides
    sides+=4
print(a[n])    