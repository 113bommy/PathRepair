a = str(input())
q = a.count('?')
l = 0
for i in 'ABCDEFGHIJ':
    if a.find(i) != -1:
        l += 1
if a[0] != '?':
    q = 10**q
else:
    q = 9 * (10**(q - 1))
l1 = 1
for i in range(0, l):
    l1 *= 10 - i
if a[0] in 'ABCDEFGHIJ':
    l1 //= 10
    l1 *= 9
print(l1 * q)
    
