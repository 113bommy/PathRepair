n = int(input())
y = input()
a = y.lower()
if len(set(a)) == 26:
    print("YES")
else:
    print("NO")