def getFirst(n):
    first = []
    while (n > 0):
        first.append(5)
        n -= 4 #heh
    return first
def getSecond(first):
    second = []
    for num in first:
        second.append(4)
    second[-1] = 5
    return second

def getString(list):
    ret = ""

    for num in list:
        ret += str(num)

    return ret

def main():
    line = input().split(" ")
    n = int(line[0])
    m = int(line[1])

    first = getFirst(n)
    second = getSecond(first)

    print(getString(first))
    print(getString(second))
main()
