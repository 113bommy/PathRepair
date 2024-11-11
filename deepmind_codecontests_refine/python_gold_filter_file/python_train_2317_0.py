for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    even = [i + 1 for i in range(n * 2) if a[i] & 1]
    odd = [i + 1 for i in range(n * 2) if not a[i] & 1]
    answers = list()

    for _ in range(n - 1):
        if len(even) > 1:
            print(even.pop(), even.pop())
        elif len(odd) > 1:
            print(odd.pop(), odd.pop())