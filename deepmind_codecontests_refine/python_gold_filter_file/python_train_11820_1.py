n = int(input())
a = list(set(map(int, input().split())))
a.sort()

works = False
for i in range(1, len(a) - 1):
    if a[i - 1] + 1 == a[i] and a[i] + 1 == a[i + 1]:
        works = True
        break

print("YES" if works else "NO")

