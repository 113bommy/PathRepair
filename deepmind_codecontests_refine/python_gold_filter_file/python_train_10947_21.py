x=int(input())
def numberTimes(n):
    if n==1:
        return 0
    if n % 2 == 0:
        m = numberTimes(int(n//2))
        if m==-1:
            return -1
        return 1+m
    if n % 3 == 0:
        m = numberTimes(int(n//3))
        if m==-1:
            return -1
        return 2+m
    if n % 5 == 0:
        m = numberTimes(int(n//5))
        if m==-1:
            return -1
        return 3+m
    return -1
for i in range(x):
    print(numberTimes(int(input())))