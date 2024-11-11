a,b=list(map(int,input().split()))
c=input()
i,j=c.index('G'),c.index('T')
c=c[min(i,j):max(i,j)+1]
d=[c[i] for i in range(0,len(c),b)]
print('YES' if '#'not in d and 'G' in d and 'T' in d else 'NO')
