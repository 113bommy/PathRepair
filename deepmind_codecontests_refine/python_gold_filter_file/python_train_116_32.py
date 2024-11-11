a=int(input())
b=list(input())
c=sorted(b)
for j in range(a):
    if b[j]!=c[j]:
        t=list(reversed(b))
        t=t.index(c[j])
        t=a-t
        print('YES')
        print(j+1, t)
        break
else:
    print('NO')