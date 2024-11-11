n, m = map(int, input().split())
r = 'YES'
zad = ''
last = ''

for i in range(n):
    s = input()
    s = set(s)
    zad += str(s)

    if len(s) > 1 or s == last:
        r = 'NO'
        
    last = s
    
zad = set(zad)

if len(zad) > 13:
    r = 'NO'

print(r)
