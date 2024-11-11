R=input
g=[list(R()) for _ in range(11)]
r,c=map(int,R().split())
r,c=(r-1)%3*4,(c-1)%3*4
f='.'
for i in range(9):
    s=g[r+i//3]
    if '.'==s[c+i%3]:
        s[c+i%3]=f='!'
print(*(''.join(v).replace(f,'!') for v in g),sep='\n')
