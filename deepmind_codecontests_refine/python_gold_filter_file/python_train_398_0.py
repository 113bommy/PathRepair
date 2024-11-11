b='b'
d='d'
p='p'
q='q'
m=[(b,d),(p,q),(d,b),(q,p)]
ans='Yes'
s=input()
if len(s)%2==1:
    ans='No'
else:
    A=s[:len(s)//2]
    B=s[len(s)//2:]
    B=B[::-1]
    for i in range(len(s)//2):
        if (A[i],B[i]) in m:
            continue
        else:
            ans='No'
print(ans)
