import sys
inpy = [x for x in sys.stdin.read().split()]
t = int(inpy[0])
index = 1
for _ in range(t):
    n = int(inpy[index])
    a, b = inpy[index+1], inpy[index+2]
    index += 3
    memo = set()
    flag = True
    for i, j in zip(a, b):
        if i > j:
            flag = False
            break
        elif j > i:
            memo.add((ord(i) - ord('a'), ord(j) - ord('a')))
    # print(memo)
    if not flag:
        print(-1)
    

    else:
        l = list(memo)
        l.sort()
        memo = set()
        match = [-1] * 26
        def get(i):
            if match[i] == -1 or match[i] == i:
                return i
            return get(match[i])
        res = 0
        for i, j in l:
            if match[i] == -1:
                match[i] = i
            i, j = get(i), get(j)
            if i != j:
                # print(i, j)
                res += 1
                match[min(i, j)] = max(i,j)
        # print(match)
        print(res)