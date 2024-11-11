n = int(input())
for test in list(map(int, input().split())):
    if test < 14:
        print("NO")
        continue
    test %= 14
    print("YES" if 0 < test < 7 else "NO")
