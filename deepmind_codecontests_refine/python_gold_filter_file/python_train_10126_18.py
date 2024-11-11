t=int(input())
s="abcdefghijklmnopqrstuvwxyz"
for q in range (0,t):
    p = [0] * 26
    l=0
    n=int(input())
    a=[]
    for i in range (0,n):
        a.append(str(input()))
    for i in range(0, n):
        w=a[i]
        for y in range (0,len(w)):
            for b in range (0,26):
                if w[y]==s[b]: p[b]+=1
    for i in range (0,26):
            if p[i]%n==0 and (p[i]>=n or p[i]==0): l+=1
    if l==26: print ("YES")
    else: print ("NO")