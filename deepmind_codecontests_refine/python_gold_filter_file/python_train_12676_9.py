def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

l, r, x, y = map(int, input().split())

if y%x!=0:
    print(0)
    exit()
    
z = y//x
ans = 0

for i in range(1, int(z**0.5)+1):
    if z%i==0:
        if gcd(i, z//i)==1 and l<=i*x<=r and l<=(z//i)*x<=r:
            ans += 1

            if i!=z//i:
                ans += 1

print(ans)