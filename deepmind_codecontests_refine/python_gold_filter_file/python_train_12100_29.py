n = int(input())

c =[]

for i in range(n):
    c.append(list(map(int, input().replace('\n','').split(' '))))

for i in range(n):
    if c[i][0]> c[i][1] or ((c[i][1]-c[i][0])%(c[i][2]+c[i][3]) is not 0) :
        print('-1')
    else:
        print(int((c[i][1]-c[i][0])/(c[i][2]+c[i][3])))
