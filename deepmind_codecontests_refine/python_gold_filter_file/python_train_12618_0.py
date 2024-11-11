def divide(n,points):
    loop=2
    while True:
        dic = {}
        for i in range(n):
            x , y = points[i]
            if (x+y)%loop not in dic:
                dic[(x+y)%loop] = []
            dic[(x+y)%loop].append(i+1)
        if len(dic)==2:
            for ele in dic:
                print(len(dic[ele]))
                print(" ".join([str(i) for i in dic[ele]]))
                return 
        dic = {}
        for i in range(n):
            x = points[i][0]
            if x % loop not in dic:
                dic [x % loop] = []
            dic[x%loop].append(i+1)
        if len(dic)==2:
            for ele in dic:
                print(len(dic[ele]))
                print(" ".join([str(i) for i in dic[ele]]))
                return
        loop *= 2

n = int(input())
points=[]
for i in range(n):
    x, y = map(int,input().split())
    points.append([x,y])
divide(n,points)
