for _ in range(int(input())):
    n, a, b = list(map(int, input().split()))
    ans = [chr(97 + i % b)for i in range(n)]
    print(''.join(ans))