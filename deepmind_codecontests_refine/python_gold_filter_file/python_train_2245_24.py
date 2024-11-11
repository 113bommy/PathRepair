n, k = map(int, input().split())
l = list(input())
m = min(l.index('G'), l.index('T'))
d = abs(l.index('G') - l.index('T'))

if d % k == 0:
    for i in range(m,m+d,k):
        if l[i] == '#':
            print("NO")
            break
    else:
        print("YES")
else:
    print("NO")            