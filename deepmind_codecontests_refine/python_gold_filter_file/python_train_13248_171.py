import sys
T = int(sys.stdin.readline())
for i in range (T) :
    N = int(sys.stdin.readline())
    if (N % 2 == 0) :
        print((N+2)//2)
    else :
        print((N+1)//2)