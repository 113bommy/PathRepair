a,b,c,d,e,f = map(int,input().split())
w = []
for i in range(f//100//a+1):
    for j in range(f//100//b+1):
        w.append(i*100*a + j*100*b)
w = set(w)
s = []
for i in range(f//c+1):
    for j in range(f//d+1):
        s.append(i*c + j*d)
s = set(s)
ans = []
for i in w:
    for j in s:
        if i != 0 and j/(i+j) <= e/(100+e) and i+j <= f:
            ans.append([j/(i+j), j+i, j])
ans.sort()
print(ans[-1][1], ans[-1][2])