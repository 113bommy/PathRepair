def twonums(n,l):
    for i in range(n):
        for j in range(i+1,n):
            t= l[i]+l[j]
            if t in l:
                return [l.index(t)+1,j+1, i+1]
    
    return [-1]

n= int(input())
l= list(map(int , input().split()))

print(*twonums(n,l))
