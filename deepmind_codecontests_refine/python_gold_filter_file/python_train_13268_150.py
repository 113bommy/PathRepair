def solve():
    count = 0
    for i in range(int(input())):
        p, q = list(map(int, input().split()))
        if p + 2 <= q:
            count += 1
    print(count)
if __name__ == "__main__":
    solve()
