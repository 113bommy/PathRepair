def main():
    n, x = map(int, input().split())
    x -= 1
    edges = [list(map(lambda v: int(v) - 1, input().split()))
             for _ in range(n - 1)]
    res = 0
    for edge in edges:
        if x in edge:
            res += 1
    if res <= 1:
        print("Ayush")
        return
    if (n - 1) % 2:
        print("Ayush")
    else:
        print("Ashish")


for _ in range(int(input())):
    main()
