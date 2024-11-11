n, m = map (int, input().split())
s = list(input())
a = ''
for i in range ( m ) :
    l, j, c1, c2 = map(str, input().split())
    l = int(l)
    j = int(j)
    if (l==j):
         if( s[l-1] == c1):
            s[l-1] = c2
    else:
        for k in range (l-1, j):
            if( s[k] == c1):
                s[k] = c2
for i in range ( n ):
    a += s[i]
print(a)