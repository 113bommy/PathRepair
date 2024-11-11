"""
NTC here
"""
from sys import setcheckinterval, stdin
setcheckinterval(1000)

# print("Case #{}: {} {}".format(i, n + m, n * m))


def iin(): return int(stdin.readline())


def lin(): return list(map(int, stdin.readline().split()))

for _ in range(iin()):
    a=input()
    b=input()
    n1=len(a)
    n2=len(b)
    i,j=n1-1,n2-1
    k=0
    while i>=0 and j>=0:
        # print(k,a[i],b[j])
        if a[i]=='1' and b[j]=='1':
            break
        elif a[i]=='1' and b[j]=='0':
            i-=1
            j-=1
        elif a[i]=='0' and b[j]=='1':
            k+=1
            i-=1
        else:
            i-=1
            j-=1
    print(k)