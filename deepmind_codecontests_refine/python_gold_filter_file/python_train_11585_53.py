import math
def function(a, b):
    if a==b:
        return 0
    if abs(a-b)<=10:
        return 1
    if a<b:
        return math.ceil((b-a)/10)
    if a>b:
        return math.ceil((a-b)/10)


if __name__=="__main__":
    t=int(input())
    for i in range(t):
        a, b=map(int, input().rstrip().split())
        print(function(a, b))