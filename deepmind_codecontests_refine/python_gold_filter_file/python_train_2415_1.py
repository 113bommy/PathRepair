n = int(input())
 
ism2 = False
if n%2 == 0:
    ism2 = True
    while n%2 == 0:
        n = n//2
 
if ism2 and n != 1:
    print('1')
    exit(0)
elif ism2 and n==1:
    print('2')
    exit(0)
 
ndiv = n
for div in range(3, int(((n+1) ** (0.5)))+1, 2):
    if n%div == 0:
        ndiv = div
        while n%div == 0:
            n = n // div
        if n != 1:
            ndiv = 1
        break
 
print(ndiv)