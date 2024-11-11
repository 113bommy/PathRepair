s = input()
n = len(s)
d = [[0]*2 for _ in range(0,n+1)]

if((ord(s[0]) >= ord('A')) and (ord(s[0]) <= ord('Z'))):
    d[0][0] = 0
    d[0][1] = 1
else:
    d[0][0] = 1
    d[0][1] = 0
    
for i in range(1,n):
    if((ord(s[i]) >= ord('A')) and (ord(s[i]) <= ord('Z'))):
        d[i][0] = d[i-1][0]
        d[i][1] = min(d[i-1][0],d[i-1][1]) + 1
    else:
        d[i][0] = d[i-1][0] + 1
        d[i][1] = min(d[i-1][0],d[i-1][1])
        
print(min(d[n-1][0],d[n-1][1]))