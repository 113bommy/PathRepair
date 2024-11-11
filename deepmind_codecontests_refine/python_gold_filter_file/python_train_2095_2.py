from collections import OrderedDict

n,m = map(int, input().split())
peoples = list(map(int, input().split()))
taxiFlag = list(map(int, input().split()))

taxi = list()
res = OrderedDict()

count = n+m
for i in range(count):
    if taxiFlag[i] == 1:
        res[peoples[i]] = 0
        taxi.append(peoples[i])

pos = 0
for i in range(count):
    if taxiFlag[i] == 0:
        way = abs(peoples[i] - taxi[pos])
        for j in range(pos+1, len(taxi)):
            newWay = abs(peoples[i] - taxi[j])
            if newWay < way:
                way = newWay
                pos = j
            else:
                break
        res[taxi[pos]] += 1

#print(res)
for k in res.values():
    print(k, end=" ")