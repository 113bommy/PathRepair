n, a, b, c, d = map(lambda x: int(x) - 1, input().split())
s = input()

if c < d:
    if "##" in s[a:d]:
        print("No")
    else:
        print("Yes")
else:
    if "##" in s[a:c] or "..." not in s[b - 1:d + 2]:
        print("No")
    else:
        print("Yes")