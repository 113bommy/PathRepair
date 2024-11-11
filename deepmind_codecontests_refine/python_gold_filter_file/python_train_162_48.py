import sys

dict = {}
dictMax = {}
value = sys.stdin.readline()
res = str.split(value, ' ')
values = []
first = int(res[0])
second = int(res[1])
diff = second - first

def getBiggestDiv(diff):

    if diff == 2 and first%2 ==0:
        return 2
    if diff == 2 and first%2 !=0:
        return second
    if diff == 0 or diff ==1:
        return second
    if diff == 3 and first%3 ==0 or second%3 ==0:
        return 3
    if diff ==3 and first%3 !=0 and second%3 != 0:
        return 2


if diff >= 4:
    print(2)
    sys.exit(0)

elif len(values) <= 4:
    maxValue = getBiggestDiv(diff)
    print(maxValue)
sys.exit(0)
# 1502393213072
