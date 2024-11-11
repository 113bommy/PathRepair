n = int(input())



p1 = 1
p2 = 2
s = 3

ans = 1

for i in range(n):
    x = int(input())
    if x==p1:
        t = p2
        p2 = s
        s = t
    elif x==p2:
        t = p1
        p1 = s
        s = t
    else:
        ans = 0
        break
        
print("YES" if ans else "NO")
