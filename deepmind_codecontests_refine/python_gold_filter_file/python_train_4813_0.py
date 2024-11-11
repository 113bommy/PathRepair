for _ in range(int(input())):
    a,b,c = list(map(int, input().split()))
    ans = None; dist = 1e10
    for i in range(1, 2*a +1):
        for j in range(i, 2*b +1, i):
            for k in range(j, 2*c + 1, j):
                if abs(a-i)+abs(b-j)+abs(c-k) < dist:
                    ans = [i, j, k]
                    dist = abs(a-i)+abs(b-j)+abs(c-k)
    print(dist)
    print(*ans)  