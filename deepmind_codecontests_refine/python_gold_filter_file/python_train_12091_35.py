lin = [int(i) for i in input().split()]
n = lin[0]
m = lin[1]
k = lin[2]
v = [int(i) for i in input().split()]
v.sort(reverse = True)

qtd = m // (k + 1)
ans = v[0] * qtd * k + v[1] * qtd
if m % (k + 1) != 0:
    r = m % (k + 1)
    ans += r * v[0]
print(ans)
    
    
