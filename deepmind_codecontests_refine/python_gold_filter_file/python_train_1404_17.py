n,k = map(int,input().split())
ai = list(map(int,input().split()))
x = ai.copy()
x.sort(reverse=True)

summ = 0
cnt = 0
lst = []
if sum(ai) <= k:
    print(len(ai))
    print(*range(1,len(ai)+1))
else:
    while k > summ:
        summ += x[-1]
        if summ > k:
            break

        lst.append(x[-1])
        x.pop(-1)
        cnt += 1

    print(cnt)
    ind = []
    for i in range(len(ai)):
        ind.append([ai[i],i+1])


    dic = []
    for i in range(len(ai)):
        dic.append([ai[i],i+1])

    #print(dic)
    dic.sort()
    flag = 0
    for i in dic:
        if flag >= cnt:
            break
        print(i[1],end=' ')
        flag += 1