import math
p,y=map(int,input().split())
def check(a):
    for i in range(2,min(int(math.sqrt(a)),p)+1):
        if a%i==0:
            return False
    return True
while y>p:
    if check(y):
        print(y)
        exit(0)
    y=y-1
print(-1)
