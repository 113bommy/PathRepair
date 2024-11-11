#n = int(input())
n, m = map(int, input().split())
t = ''
for j in range(m):
    s = input()
    k = 1
    for i in range(n):
        k = k & int(s[i])
    t += str(k)
#c = list(map(int, input().split()))
for i in range(m, 0, -1):
    l = t.count('0' * i)
    if l > 0 :
        print(i)
        break
else:
    print(0)