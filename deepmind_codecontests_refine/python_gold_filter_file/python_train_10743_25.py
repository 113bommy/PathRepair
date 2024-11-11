T = int(input())

for c in range(T):
    n, m = list(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))

    if m < n or n < 3:
        print(-1)
    else:
        print(2*sum(a))
        for i in range(n):
            if i+2 == n:
                print(i+1, i+2)
            else:
                print(i+1, (i+2)%n)
