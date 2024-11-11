n, a, b, c, d = map(int, input().split())
S = input()
if c < d:
    if "##" in S[a-1:d]:
        print("No")
    else:
        print("Yes")
else:
    f = S[b-2:d+1].find("...")
    if f != -1 and ("##" not in S[a-1:c]):
        print("Yes")
    else:
        print("No")