q=int(input())
for i in range(q):
    n=int(input())
    b = []
    x = []
    y = []
    for j in range(n):
        a=list(map(int,input().split(' ')))
        b.append(a)
        x.append(a[0])
        y.append(a[1])
    x_range = [-10 ** 5, 10 ** 5]
    y_range = [-10 ** 5, 10 ** 5]
    for i in range(n):

        if x_range[0]>x_range[1] or y_range[0]>y_range[1]:
            print(0)
            break
        if b[i][2]==1:
            if b[i][4]==0:
                if x[i]<x_range[1]:
                    x_range[1]=x[i]
        else:
            if b[i][4]==1:
                if x[i]>x_range[0]:
                    x_range[0]=x[i]
            else:
                if x[i]<x_range[1]:
                    x_range[1]=x[i]
                if x[i]>x_range[0]:
                    x_range[0]=x[i]
        if b[i][5] == 1:
            if b[i][3] == 0:
                if y[i] < y_range[1]:
                    y_range[1] = y[i]
        else:
            if b[i][3] == 1:
                if y[i] > y_range[0]:
                    y_range[0] = y[i]
            else:
                if y[i] < y_range[1]:
                    y_range[1] = y[i]
                if y[i] > y_range[0]:
                    y_range[0] = y[i]
        if x_range[0]>x_range[1] or y_range[0]>y_range[1]:
            print(0)
            break
        if i==n-1:
            print(1,x_range[0],y_range[0])