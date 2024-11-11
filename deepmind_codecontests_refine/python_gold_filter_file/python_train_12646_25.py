n = int(input())
k = input()
m = k.lower()
if len(set(m)) == 26:
    print("YES")
else:
    print("NO")