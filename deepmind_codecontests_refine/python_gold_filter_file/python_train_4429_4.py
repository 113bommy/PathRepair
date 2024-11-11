n, c = input().split()  
n, c = int(n), int(c)
l = r = w = e = 0
p = [int(s) for s in input().split()]
t = [int(s) for s in input().split()]
for i in range(n):
    q = p[i]-c*t[i] - c*w
    w +=t[i]
    a = p[n-1-i]-c*t[n-1-i] - c*e
    e +=t[n-1-i]
    l+=((abs(q)+q)//2)
    r+=((abs(a)+a)//2)
if l>r:
    print('Limak')
elif l<r:
    print('Radewoosh')
else:
    print('Tie')