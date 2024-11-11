import math
a1=0
a0=0
q = int(input())
q1=q-1
b=str(input())
for i in range(q):
    if b[i]=="0":
        a0=a0+1
    else:
        a1=a1+1
if a1==a0:
    print("2")
    print(b[:q1],b[q-1],end="")
if a1!=a0:
    print("1")
    print(b)