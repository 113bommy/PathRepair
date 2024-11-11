mas = list(map(int, input().split()))
r = mas[0]
d = mas[1]
mas = list(map(int, input().split()))
t = mas[0]
n = 0
for j in range(t):    
    mas = list(map(int, input().split()))
    xj = mas[0]; yj = mas[1]; rj = mas[2]
    s2 = xj ** 2 + yj ** 2
    if ((s2 >= (r - d) ** 2) and (s2 <= r ** 2) and (2 * rj <= d) and (s2 >= (r - d + rj) ** 2) and (s2 <= (r - rj) ** 2)):
        n += 1
print(n)