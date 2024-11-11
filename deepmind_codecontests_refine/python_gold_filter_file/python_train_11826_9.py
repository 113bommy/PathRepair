n=int(input())
coordinates=input().split()
z = list(map(int, coordinates))
s = sorted(z)
m = 0
tot = 1
for i in range(n-1):
    if i == 0:
        m=abs(s[i+1]-s[i])
    else:
        diff = abs(s[i+1]-s[i])
        if diff<m:
            m=diff
            tot=1
        elif diff==m:
            tot+=1
print(m,tot)
