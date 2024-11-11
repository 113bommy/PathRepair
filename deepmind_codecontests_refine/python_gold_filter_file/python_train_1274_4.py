
cases = int(input())
flag = 0
minn = 0

while cases:
    arr = []
    temp = []
    leng = int(input())
    str = input()
    temp = str.split(" ")
    for i in temp:
        arr.append(int(i))
    if arr[0] > 0:
        flag = 1
        big = arr[0]
        small = 0
    else:
        flag = -1
        small = arr[0]
        big = 0
    x = 0
    touch = 0
    arr.append(0)
    for x in range(0,len(arr)-1):
        if x != touch:
            continue
        else:
        #    print(">>>>> X = >>", x)
            if flag == 1:
                meh = x
                big = 0
                count = 0
        #        print("AARR{MEH}", arr[meh])
                while arr[meh + count] > 0:
        #            print(arr[meh+count] , end = '$   ')
                    if arr[meh + count] > big:
                        big = arr[meh + count]
                    count = count + 1
        #            print(big, "  ", count)
                minn = minn + big
                touch = meh + count
                flag = -1
            else:
                na = x
                count = 0
                small = -100000000000
                while arr[na + count] < 0:
        #            print("ARRRRR NAAAA",arr[na])
                    if arr[na + count] > small:
                        small = arr[na + count]
                    count = count + 1
                minn = minn + small
                if count == 1:
                    touch = na + count
                else:
                    touch = na + count
                flag = 1
            #print("MINN AFTER X = ",minn,"     ",x, "  #", touch)
        if arr[x] == 0:
            break
    print(minn)
    cases = cases - 1
    minn = 0
