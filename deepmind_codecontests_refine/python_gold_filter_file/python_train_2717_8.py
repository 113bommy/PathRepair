n = int(input())
if n==1:
    print(input())
else:
    a = [int(x) for x in input().split()]
    b = [abs(x) for x in a]
    if min(a) >= 0:
        print(sum(b) - 2 * min(a))
    elif max(a) <= 0:
        print(sum(b) + 2 * max(a))
    else:    
        print(sum(b))