q = int(input())
for i in range(q):
    a,b=map(int,input().split())
    print((abs(a-b)+9)//10)