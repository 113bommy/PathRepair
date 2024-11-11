N, A, B = map(int, input().split())
v = list(map(int, input().split()))
v.sort(reverse=True)
 
def combination(a, b):
    u, d = 1, 1
    for i in range(b):
        u *= a - i
        d *= b - i
    
    return u // d
 
s_i = sum(v[:A])
c_i = A
ans = 0
a = A
while s_i * a == sum(v[:a]) * c_i and a <= B:
    last_num = None
    c = 0
    for i in range(a):
        n = v[i]
        if n == last_num:
            c += 1
        else:
            c = 0
        
        last_num = n
 
    ans += combination(v.count(v[a - 1]), c + 1)
    a += 1
 
print(sum(v[:A]) / A)
print(ans)
