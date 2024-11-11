def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))

r,c=[int(x) for x in input().split()]

if r==c==1:
    print(0) #impossible
else:
    ans=[[-1 for _ in range(c)] for __ in range(r)]
    if r==1:
        for i in range(1,c+1):
            ans[0][i-1]=i+1
    elif c==1:
        for i in range(1,r+1):
            ans[i-1][0]=i+1
    else:
        for i in range(r):
            for j in range(c):
                #row gcd is 1,2,3,...r
                #col gcd is r+1,r+2,...r+c
                ans[i][j]=(i+1)*((j+r)+1)

    multiLineArrayOfArraysPrint(ans)