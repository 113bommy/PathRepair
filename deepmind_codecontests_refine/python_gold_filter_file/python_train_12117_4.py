def solve(arr,n):
    d = {}
    for c in arr:
        pos,x = c
        index = pos+x
        if not d.get(pos):
            d[pos] = []
        d[pos].append(index)
        
    for i in d:
        v = d[i]
        for j in v:
            k = d.get(j)
            if k:
                for a in k:
                    if a == i:
                        return "YES"
    return "NO"



    

def main():
    # vars = list(map(int, input().split(" ")))
    # k= int(input())
    n = int(input())

    # s = input()
    # a = list(map(int, input().split(" ")))
    # b = list(map(int, input().split(" ")))
    # c = list(map(int, input().split(" ")))
    res = []
    for _ in range(n):
       arr = list(map(int, input().split(" ")))
       res.append(arr)
    print(solve(res,n))
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