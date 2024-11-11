from sys  import stdin,stdout
from collections import deque
st=lambda:list(stdin.readline().strip())
li=lambda:list(map(int,stdin.readline().split()))
mp=lambda:map(int,stdin.readline().split())
inp=lambda:int(stdin.readline())
pr=lambda n: stdout.write(str(n)+"\n")
from random import randint

    
mod=1000000007
def solve():
    l,r=mp()
    if r-l<2:
        pr(-1)
    else:
        if l%2==0:
            print(l,l+1,l+2)
        else:
            if r-l-1>=2:
                print(l+1,l+2,l+3)
            else:
                pr(-1)
            

for _ in range(1):
    solve()
