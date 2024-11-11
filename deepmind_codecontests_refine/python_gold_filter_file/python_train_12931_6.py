n, m = list(map(int, input().split(" ")))
s = input().split(" ")
t = input().split(" ")
def f(n, m, s, t, y):
    y -=1
    return s[y % n]+t[y % m]
    

res = []
for q in range(int(input())):
    y = int(input())
    res.append(f(n, m, s, t, y))
for x in res:
    print(x)
    
