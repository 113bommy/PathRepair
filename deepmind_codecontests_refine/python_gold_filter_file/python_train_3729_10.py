n, m = map(int, input().split())
py = []
mli = [0]*n
li = [""]*m

for i in range(m):
    p,y = map(int, input().split())
    py.append([p,y,i])

py.sort(key=lambda x: x[1])

for p,y,i in py:
    mli[p-1] += 1
    pi = str(p).zfill(6)
    yi = str(mli[p-1]).zfill(6)
    li[i] = pi+yi

for i in li:
    print(i)