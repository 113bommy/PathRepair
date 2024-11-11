n = int(input())
a = list(map(int,input().split()))
c = [0]
for i in range(len(a)):
    c.append(c[-1]+a[i])
q = int(input())
for _ in range(q):
    l,r = map(int,input().split())
    print((c[r]-c[l-1])//10)
