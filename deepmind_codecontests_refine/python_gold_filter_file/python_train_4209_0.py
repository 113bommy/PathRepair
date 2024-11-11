def solve(n,k,arr):
    count = 0
    for i in range(k):
        d = {1: 0, 2: 0}
        for j in range(0,n,k):
            d[arr[i+j]] += 1
        ones = d[1]
        twos = d[2]
        if ones and twos:
            count += min(ones, twos)
    return count

def main():
    n,k = list(map(int, input().split(" ")))
    # n = int(input())
    arr = list(map(int, input().split(" ")))
    # s = input()
    # x,y = list(map(int, input().split(" ")))
    # b = list(map(int, input().split(" ")))
    # c = list(map(int, input().split(" ")))
    # res = []
    # for _ in range(n):
    #    arr = list(map(int, input().split(" ")))
    #    res.append(arr)
    print(solve(n,k,arr))
    # i = 0
    # inputpath = 'input.txt'
    # outPath = 'output.txt'
    # with open(inputpath) as fp:
    #     line = fp.readline()
    #     cnt = 1
    #     while line:
    #         if cnt == 1:
    #             i = int(line)
    #         else:
    #            arr = list(map(int, line.split(" ")))
    #            res.append(arr)  
    #         cnt += 1
    #         line = fp.readline()
    # s = solve(res,i)
    # with open(outPath, 'a') as out:
    #     out.write(str(s))


main()