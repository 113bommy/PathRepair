for _ in range(int(input())):
    n = int(input())
    x = list(map(int,input().split()))
    j = [a for a in x if a % 2 == 1]
    if len(j) == n:
        print('Yes')
    else:
        print('No')
