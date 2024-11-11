s = list(input())
n = len(s)
arr = [0]*n
i=1
while i<n:
    if s[i] == 'b':
        arr[i-1] = 1
    while s[i] == 'b':
        i+=1
        if i==n:
            break
    if i!=n and s[i-1]=='b':
        arr[i-1] = 1
    i+=1
if s[n-1]!='b':
    arr[-1] = 1
print(" ".join(map(str,arr)))