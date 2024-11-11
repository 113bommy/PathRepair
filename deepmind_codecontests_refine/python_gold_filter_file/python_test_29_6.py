t = int(input())
for i in range(0,t):
    d = int(input())
    a = list(map(int,input().split()))
    c = sum(a)
    d = []
    count = 0
    num = 0
    for ele in a:
        if ele == 1:
            count = count +1
        elif ele == 0:
            num = num+1
    #print(count ,num)
    if count == 1 and num == 0:
        print(1)
    elif count == 1 and num > 0:
        print(pow(2,num))
    elif count>1:
        print(count * pow(2,num))
    else:
        print(0)