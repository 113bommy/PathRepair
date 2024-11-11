n, a, b, c, d = map(int, input().split())
s = input()
if "##" in s[min(a,b):max(c,d)]:
    print("No")
    exit()
if c < d:
    print("Yes")
else:
    if "..." in s[b-2:d+1]:
        print("Yes")
    else:
        print("No")