T = int(input())

while T > 0:
    T-=1
    a = list(map(int, input().split()))
    if max(a) - sum(a) + max(a) < 2:
        print("Yes")
    else:
        print("No")