a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())

ans = 0
for i in range(d+1):
    m1 = min(a, i)*e
    m2 = min(b,c,d-i)*f
    
    ans = max(ans, m1 + m2)
    
print(ans)