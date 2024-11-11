for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    print("YES" if a[0] < a[-1] else "NO")