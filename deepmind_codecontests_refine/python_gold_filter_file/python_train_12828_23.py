t = int(input())

def getMin(n,x,y):
    z=x+y
    if z < n + 1:
        return 1
    elif z == n + 1:
        return 2
    else:
        return n - (2 * n - (x + y) - 1)

def getMax(n,x,y):
    z=x+y
    if z < n + 1:
        return x + y - 1
    else:
        return n
    

for _ in range(t):
    n,x,y=map(int,input().split())
    if n == 1:
        print("1 1")
    elif x == n and y == n:
        print(str(n) + " " + str(n))
    else:
        print(*[getMin(n,x,y),getMax(n,x,y)])






#10 -> 3, 4
#7 + 6 = 13
#5 8 for 10, 13
#4 10
#8 6
#9 5
#7 7
#10 4
#20, 13, 14, 5

#5 9 for 10, 14
#10 5
#9 6
#8 7
#7 8
#6 9


#3, 5 = 8
#1 7
#7 1
#2 6
#6 2




#7 7 7 7 7 7
#3 7 8 8 8 8
