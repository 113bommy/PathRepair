t=int(input())
for _ in range(t):
    n,m,x,y=map(int, input().split(" "))
    count=0
    for i in range(n):
        patt=input().split("*")
        if y<2*x:
            for i in range(len(patt)):
                # if len(patt[i]) == 1:
                #     count+=x
                # elif :
                count+=(len(patt[i])//2)*y + (len(patt[i])%2)*x
        else:
            for i in range(len(patt)):
                count+=len(patt[i])*x
    print(count)


# .*..*....**.**...*
# .***.*.*..*..****.
# ..*..*..*..*..*..*

# if 1x2 is cheaper
# .*..*....**.**...*
# 1 2  2 2   1  2 1

# if 1x1 is cheaper
# .*..*....**.**...*
# 1 11 1111  1  111
