
n, x, y = map(int, input().split())
a = list(map(int, input().split()))
maxi = max(a)
for _ in range(x):
    a.insert(0, maxi+1)
for _ in range(y):
    a.append(maxi+1)

for i in range(x, n+x):
    mini = min(a[i-x:i+y+1])
    if mini == a[i]:
        if(a[i-x:i+y+1].count(mini)) == 1:
            print(i-x+1)
            break
