n = int(input())
a = ['']*n
b = ['']*n
c = ['']*n

for i in range(n):
    s = input()
    k = s.find(' ')
    a[i] = s[:k]
    b[i] = s[k+1:]
k = 0
p = list(map(int, input().split()))
for j in p:
    i = j - 1
    if k == 0:
        c[k] = min(a[i],b[i])
        k+=1
    else:
        if a[i] > c[k-1] and not (b[i] > c[k-1] and b[i] < a[i]):
            c[k] = a[i]
        elif b[i] > c[k-1]:
            c[k] = b[i]
        else:
            print('NO')
            break
        k+=1
else:
    print('YES')