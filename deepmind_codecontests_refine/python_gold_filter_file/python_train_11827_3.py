def budget(o,data):
    coast = 0
    arr = []
    for i in range(len(data)):
        arr.append((((i+1)*o) + data[i]))
    arr = sorted(arr)
    for j in range(o):
        coast+=arr[j]

    return coast

def getTotalItems(mid,data,money):
    total = 0
    for i in range(mid):
        total+=(((i+1)*mid) + data[i])
    if total <= money:
        return True
    else:
        for j in range(mid,len(data)):
            total-=((((j-mid)+1)*mid) + data[j-mid])
            total+=(((j+1)*mid) + data[j])
            # print(f"m is {mid} and total is {total}")
            if total <= money:
                return True
    return False
def bsItems(data,mon):
    r = len(data)
    l = 0
    money = mon
    lCoast = 0
    while (r - l) > 0:
        m = (l+r+1) //2
        if budget(m,data) > money:
            r = m - 1
        else:
            l = m
    minmumCoast = budget(l,data)
    return l,minmumCoast
def getMinTotalCoast(data,mi,money,items2):
    total2 = mi
    n2 = len(data)
    print(f"m is {mi}")
    for i in range(items2):
        total2-=(((i+1)*items2) + data[i])
    if total2 >= 0:
        return True
    else:
        print(total2)
        # total2 = mi
        for j in range(items2,n2):
            indx = j-items2
            total2 += (((indx + 1) * items2) + data[indx])
            print(total2)
            total2-=(((j+1)*items2) + data[j])
            print(total2)
            if total2 >= 0:
                return True

    return False
def bsTotalCoast(data,money,items2):
    r = money
    l = 0
    while (r - l) > 0:
        min_coast = (l+r) // 2
        if getMinTotalCoast(data,min_coast,money,items2):
            r = min_coast
        else:
            l = min_coast + 1
    return r

n,s = map(int,input().split(" "))
items = list(map(int,input().split(" ")))
k,t = bsItems(items,s)
print(k,t,end= " ")