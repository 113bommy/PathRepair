n= int(input())
for _ in range(n):
    x,y,a,b = map(int, input().split())
    if(x*a)!=(y*b):
        print("NO")
    else:
        print("YES")
        arr = [[0 for i in range(y)] for j in range(x)]
        j=0
        for i in range(x):
            ct=0
            if(j>=y):
                j=0
            for k in range(y):
                if(ct<a):
                    if(j>=y):
                        j=0
                    arr[i][j]=1
                    j+=1
                    ct+=1
                else:
                    break
        for i in range(x):
            for j in range(y):
                print(arr[i][j], end="")
            print()