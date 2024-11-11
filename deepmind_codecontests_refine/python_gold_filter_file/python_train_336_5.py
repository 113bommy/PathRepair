m = pow(10, 9) + 7
n = int(input())
a = 2
fact = [1]*(n+1)
po = [1]*(n+1)

for i in range(1, n+1):
    fact[i]= (fact[i-1] * i)% m
    po[i] = (2*po[i-1]) %m

print((fact[n] - po[n-1])%m)