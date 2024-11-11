n = int(input())

p = [-1]*501

q = 1

for i in range(1,n):
    for j in range(i+1,n+1):
        if p[j-i] == -1:
            if j == n:
                print(q)
            else:
                print(q,end = ' ')
            ind = j-i
            while ind <= len(p)-1:
                p[ind] = q
                ind += (j-i)*2
            q += 1
        else:
            if j==n:
                print(p[j-i])
            else:
                print(p[j-i],end = ' ')
