if __name__ == '__main__':
    n = int(input())
    grade = dict()
    mem = []
    ans = ''
    while n:
        n -= 1
        name, score = input().strip().split()
        mem.append(tuple([name, int(score)]))
        score = int(score)
        if name not in grade:
            grade[name] = score
        else:
            grade[name] += score
    maxm = max(grade.values())
    tmp = dict()
    for item in mem:
        name = item[0]
        score = item[1]
        if name not in tmp:
            tmp[name] = score
        else:
            tmp[name] += score
        if tmp[name] >= maxm and grade[name] == maxm:
            ans = name
            break
    print(ans)