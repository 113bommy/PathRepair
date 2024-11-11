n = int(input())
S = input()

s = S.lower()

if len(set(s)) == 26:
    print("YES")
else:
    print("NO")