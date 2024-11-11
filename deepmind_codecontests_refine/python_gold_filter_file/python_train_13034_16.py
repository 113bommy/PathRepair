t=int(input())
#print(bin(t).replace("0b",""))
for i in range(t):
    n=int(input())
    ar=[int(x) for x in input().split()]
    sm=0
    xor=0
    for j in range(n):
        sm+=ar[j]
        xor^=ar[j]
    if(sm==2*xor):
        print("0")
    else:
        print("2")
        print(xor,sm+xor,end=" ")
    print()
