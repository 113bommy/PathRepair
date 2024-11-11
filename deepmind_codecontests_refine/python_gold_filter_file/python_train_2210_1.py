n = int(input())
a = list(map(int, input().split()))
c = [0]*24
for i in range(n):
    c[a[i]] += 1

s = c[0]*(c[0]-1)//2
for i in range(1, 11):
    s += c[i]*c[-i]

print(s)

