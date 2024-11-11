n = int(input())
m = []
for i in range(n):
    a,b = map(int,input().split())
    if a != b:
        print('rated')
        exit()
    m.append(a)
    m.append(b)
k = sorted(m,reverse=True)
if k == m:
    print('maybe')
else:
    print('unrated')
