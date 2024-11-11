n = int(input())
l = -2000000000
r = 2000000000
for _ in range(n):
    s = input().split()
    x = int(s[1])
    if s[0] == ">" and s[2] == "Y":
        l = max(l, x + 1)
    elif s[0] == ">" and s[2] == "N":
        r = min(r, x)
    elif s[0] == ">=" and s[2] == "Y":
        l = max(l, x)
    elif s[0] == ">=" and s[2] == "N":
        r = min(r, x - 1)
    elif s[0] == "<" and s[2] == "Y":
        r = min(r, x - 1)
    elif s[0] == "<" and s[2] == "N":
        l = max(l, x)
    elif s[0] == "<=" and s[2] == "Y":
        r = min(r, x)
    elif s[0] == "<=" and s[2] == "N":
        l = max(l, x + 1)
    # print(l, r)
if r - l >=0:
    print(l)
else:
    print("Impossible")