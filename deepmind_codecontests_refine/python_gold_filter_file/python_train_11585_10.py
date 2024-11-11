import math
for _ in range(int(input())):
    a,b=map(int,input().split())
    diff=abs(a-b)
    # print(diff//10 + 1)
    print(math.ceil(diff/10) )
    # 0=0
    # 1-10 = 1
    # 11-20 = 2
    # 21-30 = 3
    