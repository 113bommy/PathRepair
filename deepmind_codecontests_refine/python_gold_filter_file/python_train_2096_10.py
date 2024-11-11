import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range (int(input())):
    n = int(input())
    i = 3
    ans = -1
    while(i<=360):
        x = 180/i
        if (n*i)%180 == 0 and x*(i-2)>=n:
            ans = i
            break
        i+=1
    print(ans)