for _ in range(int(input())):
    n, s, k = map(int, input().split())
    A = [int(a) for a in input().split()]
    
    for i in range(k + 1):
        if 1 <= (s - i) <= n and (s - i) not in A:
            print(i)
            break
        elif 1 <= (s + i) <= n and (s + i) not in A:
            print(i)
            break