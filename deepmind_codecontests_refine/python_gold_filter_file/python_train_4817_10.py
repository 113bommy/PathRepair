t = int(input())
for i in range(t):
    n = int(input())
    data = list(map(int , input().split()))
    data = sorted(data , reverse= True)
    sd = sum(data[1:])
    if data[0] > sd:
        print('T')
    elif data[0] == sd:
        print('HL')
    else:
        temp  = sd - data[0]
        if temp% 2 == 0:
            print('HL')
        else:
            print('T')