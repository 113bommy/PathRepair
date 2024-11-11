n, k = map(int, input().split())
s=[]
for i in range (n):
    s.append(input())
p=[1, 1]
v=0
for i in range (n):
    for j in range(n):
        if s[i][j]=='.':
            iv=i
            jv=j
            vi=0
            vj=0
            while (jv-1>=0 and j-jv<k and s[i][jv-1]=='.'):
                jv-=1
            while (jv!=n and jv-j<k and s[i][jv]=='.'):
                jv+=1
                vj+=1
            if (vj-(k-1))<0:
                vj=0
            else:
                vj-=(k-1)
            while (iv-1>=0 and i-iv<k and s[iv-1][j]=='.'):
                iv-=1
            while (iv!=n and iv-i<k and s[iv][j]=='.'):
                iv+=1
                vi+=1
            if(vi-(k-1))<0:
                vi=0
            else:
               vi-=(k-1)
            if vi+vj>v:
                v=vi+vj
                p[0]=i+1
                p[1]=j+1
print(' '.join(str(i) for i in p))


