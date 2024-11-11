t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    test=0
    i=1
    while i < n:
        if a[i] <= a[i-1]:
           test = 1
        i += 1
    if n % 2 == 0 or test == 1:
        print("YES")
    else:
        print("NO")
