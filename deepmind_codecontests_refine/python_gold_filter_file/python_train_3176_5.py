n,m=[int(t) for t in input().split()]
for i in range((10**(n-1))+1,10**(n)):
    if i%m==0:
        print(i)
        exit()
print(-1)
