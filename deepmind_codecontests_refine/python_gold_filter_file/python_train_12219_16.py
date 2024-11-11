input()
a = list(map(int, input().split()))
ch = 0
bi = 0
ba = 0
for i in range(0, len(a), 3):
    ch += a[i]
for j in range(1, len(a), 3):
    bi += a[j]
for k in range(2, len(a), 3):
    ba += a[k]
if max(ch,bi,ba) == ch:print("chest")
elif max(ch,bi,ba) == bi:print("biceps")
else:print("back")