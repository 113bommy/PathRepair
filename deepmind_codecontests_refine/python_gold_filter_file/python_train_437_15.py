import sys
t=int(sys.stdin.readline().strip())
for i in range(0,t):
    len=int(sys.stdin.readline().strip())
    array=list(map(int,sys.stdin.readline().strip().split()))
    m=min(array)
    k=0
    for j in set(array):
        if j!=m:

            k+=1
    print(k+1)
