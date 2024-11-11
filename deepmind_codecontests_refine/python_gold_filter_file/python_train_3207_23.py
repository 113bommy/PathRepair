s=input()
init=[1]*len(s)

for k in range(len(s)-2):
    if s[k]=='R' and s[k+1]=='R':
        init[k+2]+=init[k]
        init[k]=0
for k in range(len(s)-1,0,-1):
    if s[k]=='L' and s[k-1]=='L':
        init[k-2]+=init[k]
        init[k]=0
print(*init)