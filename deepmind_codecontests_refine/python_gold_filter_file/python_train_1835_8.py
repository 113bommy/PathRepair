n=int(input())
s=input()
m=0
for i in range(len(s)):
    for j in range(i,len(s)):
        ch=s[i:j+1]
        test=True
        for k in ch:
            if k in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' :
                test=False
                break
        E=set(ch)
        if test :
            m=max(m,len(E))
print(m)
        

