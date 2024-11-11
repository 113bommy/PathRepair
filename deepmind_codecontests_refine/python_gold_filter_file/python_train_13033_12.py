import sys 
#sys.stdin = open('input')

M = 1000000007

x, n = map(int, input().split(' '))
ft = set()
while(x != 1):
    i = 2
    while(x % i != 0 and i*i <= x):
        i += 1
    if(x % i != 0):
        ft.add(int(x))
        break
    else:
        ft.add(i)
        x /= i
# print(ft)

ans = 1
for i in ft:
    pp = i 
    while(pp <= n):
        ans *= pow(int(i), int(n//pp), M)
        ans %= M
        pp *= i
print(ans)