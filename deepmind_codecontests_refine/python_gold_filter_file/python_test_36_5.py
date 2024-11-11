import math
def isDiv(x):
    for i in range(2,x):
        if x % i == 0:
            return True
    return False

T = int( input() )
for t in range(T):
    n = int( input() )
    A = input().split()
    A = [int(A[i]) for i in range(n)]
    if isDiv(sum(A)):
        print(len(A))
        for i in range(len(A)):
            print(i+1, end = ' ')
        print()
    else:
        print(len(A)-1)
        removed = False
        for i in range(len(A)):
            if not removed and A[i] %2:
                removed = True
                continue
            print(i+1, end = ' ')
        print()
        