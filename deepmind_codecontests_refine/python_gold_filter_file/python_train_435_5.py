from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
    # a=list(map(int,stdin.readline().split()))
    s,s1=input().split()
    ln=len(s)
    ln1=len(s1)
    l=list(s)
    if s<s1:
        print(s)
        continue
    for i in range(ln):
        ch=s[i]
        p=-1
        mn=ch
        for j in range(i+1,ln):
            if s[j]<=mn:
                p=j
                mn=s[j]
        if mn!=ch:
            l[i],l[p]=l[p],l[i]
            break
    s=''.join(l)
    if s<s1:print(s)
    else:print('---')