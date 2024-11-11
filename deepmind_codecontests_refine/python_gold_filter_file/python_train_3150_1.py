for _ in range(int(input())):
    S = input()
    N = int(input())
    B = list(map(int,input().split()))
    counts = {}
    levels = []
    for i in range(len(S)):
        if(S[i] in counts):
            counts[S[i]] +=1
        else:
            counts[S[i]] = 1
    pos = []
    currlevel = []
    for i in range(N):
        if(B[i]==0):
            currlevel.append(i)
            pos.append(i)
        # print("currlevel",currlevel)
    levels.append(currlevel)
    # print("pehla level",levels)
    # print("pos",pos)
    while(len(pos)<N):
        counter = 0
        currlevel = []
        for i in pos:
            counter+=i
        sub = len(pos)
        for i in range(N):
            if(i in pos):
                sub-=2
                counter-=sub
            else:
                if(counter==B[i]):
                    currlevel.append(i)
                    counter-=sub
                else:
                    counter-=sub
        if(len(currlevel)>0):
            pos.extend(currlevel)
            levels.append(currlevel)
        # print(levels,pos)
    tocheck = [0]*N
    # print(levels)
    for i in range(len(levels)):
        for j in levels[i]:
            tocheck[j] = (i+1)
    # print(tocheck)
    alpha = list(counts.keys())
    alpha.sort(reverse=True)
    # print(alpha)
    keyl = 0
    finans = [0]*N
    for i in range(1,len(levels)+1):
        while(True):
            if(counts[alpha[keyl]]>=len(levels[i-1])):
                for j in range(len(tocheck)):
                    if(j in levels[i-1]):
                        finans[j] = alpha[keyl]
                keyl+=1
                break
            else:
                keyl+=1
    s = ""
    for i in finans:
        s+=i
    print(s)
