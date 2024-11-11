for _ in range(int(input())):
    a, b, c = list(map(int, input().split()))
    ans = 71227122
    abc = []
    for A in range(1, 10001, 1):
        for B in range(A, 20001, A):
            for C in [c//B*B, (c//B+1)*B]:
                if C < B:
                    C = B
                diff = abs(A-a) + abs(B-b) + abs(C-c)
                if diff < ans:
                    ans = diff
                    abc = [A, B, C]
    print(ans)
    print(*abc)
