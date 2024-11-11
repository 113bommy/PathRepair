n = int(input())
a = list(map(int,input().split()))
r = max(a)+1
s = []
t = [0]*r
for i in range(r):
    s.append([])
for i in range(2,r):
    if(s[i] == []):
        for j in range(1,-(-r//i)):
            s[i*j].append(i)
for i in range(n):
    for j in range(len(s[a[i]])):
        t[s[a[i]][j]] += 1
if(max(t) == n):
    print('not coprime')
elif(max(t) <= 1):
    print('pairwise coprime')
else:
    print('setwise coprime')