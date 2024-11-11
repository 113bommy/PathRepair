import sys
n=int(input())
for i in range(n+1):
    k=1
    while (2**k-1)*(2**(k-1))<n-i:
        k+=1
    if (2**k-1)*(2**(k-1))==n-i and n%((2**k-1)*(2**(k-1)))==0:
        print(n-i)
        sys.exit()
