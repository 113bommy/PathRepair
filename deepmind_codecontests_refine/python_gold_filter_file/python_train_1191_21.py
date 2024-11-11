n = int(input())
a = list(map(int, input().split()))
b = list(a)
b.sort()
mn = 0
mx = 0
for i in range(len(a)):
    if a[i] != b[i]:
        mn = i
        break
for i in range(len(a)-1, -1, -1):
    if a[i] != b[i]:
        mx = i
        break
a = a[:mn]+ a[mn:mx+1][::-1] + a[mx+1:]
if a == b:
    print("yes")
    print(mn+1, mx+1)
else:
    print("no")
    