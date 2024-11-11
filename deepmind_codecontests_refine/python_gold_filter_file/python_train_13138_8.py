def z_func(s):
    l = 0
    r = 0
    n = len(s)
    z = [0]*n
    z[0] = n
    for i in range(1, n):
        if i <= r:
            z[i] = min(r-i+1, z[i-l])
        while (i+z[i] < n) and (s[z[i]] == s[i+z[i]]):
            z[i] += 1
        if i+z[i]-1 > r:
            l = i
            r = i+z[i]-1
    return z

string = input()
n = len(string)
z = z_func(string)
l = 0

for i in range(n-1,0,-1):
    if z[i]==n-i:
        for j in range(1,i):
            if z[j]>=z[i]:
                l = z[i]
                break

if l>0:
    print(string[0:l])
else:
    print('Just a legend')
