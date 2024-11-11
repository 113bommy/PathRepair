def gcd(a, b):
    if(not b):
        return a
    return gcd(b, a % b)


from sys import exit
n = int(input())
if(n < 3):
    print('No')
    exit()
need = (n + 1) * n // 2
q = -1
for i in range(1, n + 1):
    if(gcd(need - i, i) > 1):
        q = i
        break;
if(q == -1):
    print('No')
    exit()
print('Yes')
print(1, q)
print(n - 1, end=' ')
for i in range(1, n + 1):
    if(i != q):
        print(i, end=' ')
#print('')
#print(q, need - q)