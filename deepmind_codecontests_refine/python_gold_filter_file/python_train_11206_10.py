n, k = map(int, input().split())
mod = set()
b = True
for i in range(1, k+1):
    if n % i in mod:
        b = False
        break
    else:
        mod.add(n%i)
if b:
    print('Yes')
else:
    print('No')