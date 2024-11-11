def main():
    l = [int(x) for x in input().split()]

    car = 0
    flag = False
    if (l[3]>=l[2]):
        if(2*l[2] >= l[3]):
            flag = True
            car = l[3]
    else:
        if(2*l[3] >= l[2]):
            flag = True
            car = l[2]

    if (l[0]<=l[3] or l[1]<=l[3]):
        flag = False


    if (l[1]<=2*l[3]):
        l[1] = 2*l[3] + 1
        if (l[0]<=l[1]):
            l[0] = l[1] + 1

    if(flag):
        print(l[0])
        print(l[1])
        print(car)
    else:
        print(-1)
main()
