import math as m
n = int(input())
l1 = []
l2 = []
for i in range(1,n+1):
    if i%2==0:
        l1.append(i)
    else:
        l2.append(i)
if m.gcd(sum(l1),sum(l2))<=1:
    print("No")
else:
    print("Yes")
    print(len(l1),*l1)
    print(len(l2),*l2)