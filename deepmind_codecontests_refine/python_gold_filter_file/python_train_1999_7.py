n = list(map(int, input().split()))
h = list(map(int, input().split()))
a = []
i = 0
while i < len(h):
    if h[i] not in a:
        if len(a) < n[1]:
            a.insert(0, h[i])
        else:
            a.pop()
            a.insert(0, h[i])
    i+=1
print(len(a))
i = 0
while i < len(a):
    print(a[i], end=' ')
    i+=1

