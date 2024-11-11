t = int(input())
for _ in range(t):
    s = input()
    t = input()
    ans = False
    for i in set(s):
        if i in t:
            ans = True
            break
    print("YES" if ans else "NO")