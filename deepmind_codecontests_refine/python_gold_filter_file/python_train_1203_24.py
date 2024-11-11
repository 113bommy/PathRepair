n=input()
mx,cn=0,1
for i in range(len(n)):
    if n[i] in 'AEIOUY':
        mx = max(mx, cn)
        cn=1
        continue
    else:
        cn+=1
mx=max(mx,cn)
print(mx)