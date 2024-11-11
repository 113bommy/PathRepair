from sys import stdin
def diff(n):
    count=0
    while(n):
        if(n&1==1):
            count+=1
        n=n>>1
    return 1<<count
n=int(stdin.readline())
for i in range(n):
    t=int(stdin.readline())
    print(diff(t))