import sys
LI=lambda:list(map(int, sys.stdin.readline().split()))
MI=lambda:map(int, sys.stdin.readline().split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline())

t='RGBY'
s=SI()
a=[]
for i in range(4):
    for j in range(4):
        for k in range(4):
            for l in range(4):
                if len(set([i, j, k, l]))==4:
                    a.append(t[i]+t[j]+t[k]+t[l])
for t in a:
    ok=True
    for i in range(0, len(s), 4):
        for j in range(4):
            if i+j<len(s) and t[j]!=s[i+j] and s[i+j]!='!':
                ok=False
    if ok:
        break
ans={c:0 for c in t}
for i in range(0, len(s), 4):
    for j in range(4):
        if i+j<len(s) and s[i+j]=='!':
            ans[t[j]]+=1
print(ans['R'], ans['B'], ans['Y'], ans['G'])
