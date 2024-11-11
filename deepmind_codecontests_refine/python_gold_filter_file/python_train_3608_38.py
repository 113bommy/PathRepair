n = input()
li = [x for x in map(int, input().split())]

#n=4
#li=[2,2,2,2]

tot = sum(li)
presum=li[0]
for i in range(1, len(li)+1):

    if presum >= tot / 2 :
        print(i)
        break
    presum += li[i]