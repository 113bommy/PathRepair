n = int(input())
p = list(map(int,input().split()))

a = list(range(30000, 30000*(1+n), 30000))
b = a[::-1]

for i,p_tmp in enumerate(p):
    b[p_tmp-1] += i

print(' '.join(map(str, a)))
print(' '.join(map(str, b)))