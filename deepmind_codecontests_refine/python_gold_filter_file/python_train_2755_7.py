x = int(input())
l = list(map(int,input().split()))
if x == 3:
    print(l[-1]-l[0])
else:
    list = []
    k = []
    for tt in l[1:-2]:
        for num in range(1,x):
            if l[num] == tt:
                k.append(l[num+1]-l[num-1])
            else:
                k.append(l[num] - l[num-1])
        list.append(max(k))
        k = []
    print(min(list))