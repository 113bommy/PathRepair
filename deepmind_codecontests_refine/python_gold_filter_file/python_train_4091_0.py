import sys
def ceil(a, b):
    return -(-a // b)

def answer(n, W, w):
    #create tuples of values and indices and sort by values. Remember 1-based indexing.
    tup_list = []
    for i in range(n):
        tup_list.append((i+1, w[i]))
    tup_list.sort(key=lambda tup:tup[1], reverse=True)
    #print(tup_list)
    indx = 10**10
    for i in range(n):
        if tup_list[i][1] > W:
            continue
        elif tup_list[i][1] >= ceil(W, 2):
            print('1')
            print(tup_list[i][0])
            return
        else: #largest value < ceil(W, 2)
            indx = i
            break
    if indx == 10**10: #Nothing small enough.
        print('-1')
        return
    #indx contains small enough values.
    summ = tup_list[indx][1]
    addrs = [tup_list[indx][0]]
    for i in range(indx+1, n):
        summ += tup_list[i][1]
        addrs.append(tup_list[i][0])
        if summ >= ceil(W, 2):
            print(i - indx + 1)
            print(' '.join(map(str,addrs)))
            return
    #no soln
    print('-1')
    return #null

def main():
    t = int(input())
    while t:
        n, W = [int(i) for i in sys.stdin.readline().split()]
        w = [int(i) for i in sys.stdin.readline().split()]
        answer(n, W, w)

        t -= 1
    return
main()