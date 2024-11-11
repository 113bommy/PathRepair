R,G,B,N = map(int, input().split())
c = 0
for i in range(0,int(N/R)+1):
    for j in range(0,int((N-R*i)/G)+1):
        if (N-R*i-G*j)%B == 0:
            c += 1
print(c)
