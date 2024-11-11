n = int(input())

print( n*(n-1)//2 - n//2)

com = []

if (n%2 == 1):
    com.append([n])
    n -= 1
for i in range(1,1+n//2):
    com.append([i,n+1-i])

for i in range(len(com) - 1):
    for j in com[i]:
        for k in com[i+1 : ]:
            for l in k:
                print('{} {}'.format(j,l))