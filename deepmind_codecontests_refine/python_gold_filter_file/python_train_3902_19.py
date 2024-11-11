import sys

N, M = map(int, sys.stdin.readline().split())
count = 0

for i in range(N):
    if i%2 == 0:
        print("#"*M)
    elif i%2 != 0:
        if count == 0:
            print("."*(M-1)+"#")
            count = 1
        elif count == 1:
            print("#"+"."*(M-1))
            count = 0