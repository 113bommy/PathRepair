s=str(input())
a=s.find('h')
A=s[a:]
b=A.find('e')
B=A[b:]
c=B.find('l')
C=B[c+1:]
d=C.find('l')
D=C[d:]
e=D.find('o')
if a==-1 or b==-1 or c==-1 or d==-1 or e ==-1:
    print('NO')
else:
    print('YES')

