n=input()
m=list(input())
a='qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./'
l=list(a)
if n=='R':
    for i in range(len(m)):
        c=a.find(m[i])
        m[i]=l[c-1]
else:
    for i in range(len(m)):
        c=a.find(m[i])
        m[i]=l[c+1]
print(''.join(m))