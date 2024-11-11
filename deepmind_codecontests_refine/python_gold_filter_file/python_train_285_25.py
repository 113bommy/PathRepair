import heapq

T = int(input())
Ns = []
cases = []*T
for i in range(T):
    Ns.append(int(input()))
    cases.append([list(map(int, input().split())) for _ in range(Ns[-1])])

for i in range(T):
    answer = 0
    N = Ns[i]
    case = cases[i]
    
    sa = [case[j][2]-case[j][1] for j in range(N)]
    pluss = []
    minuss = []
    for j in range(N):
        if sa[j] >= 0:
            pluss.append([case[j][0],case[j][1],case[j][2],sa[j]])
        else:
            minuss.append([case[j][0],case[j][1],case[j][2],sa[j]])
    pluss = sorted(pluss)
    minuss = sorted(minuss,reverse = True)
    hq = []
    checking = 0
    for j in range(N-len(pluss),N):
        if checking < len(pluss):
            while j > pluss[checking][0]-1:
                heapq.heappush(hq, [-pluss[checking][3],pluss[checking][1],pluss[checking][2],pluss[checking][0]])
                checking+=1
                if checking >= len(pluss):
                    break
        if len(hq)>0:
            temp = heapq.heappop(hq)
            answer += temp[2]

    for j in range(checking,len(pluss)):
        heapq.heappush(hq, [-pluss[j][3],pluss[j][1],pluss[j][2],pluss[j][0]])
        
    for j in range(len(hq)):
        temp = heapq.heappop(hq)
        answer += temp[1]

    hq = []
    checking = 0
    for j in range(len(minuss)-1,-1,-1):
        if checking < len(minuss):
            while j <= minuss[checking][0]-1:
                heapq.heappush(hq, [minuss[checking][3],minuss[checking][1],minuss[checking][2],minuss[checking][0]])
                checking+=1
                if checking >= len(minuss):
                    break
        if len(hq)>0:
            temp = heapq.heappop(hq)
            answer += temp[1]

    for j in range(checking, len(minuss)):
                    heapq.heappush(hq, [minuss[j][3],minuss[j][1],minuss[j][2],minuss[j][0]])

    for j in range(len(hq)):
        temp = heapq.heappop(hq)
        answer += temp[2]
    print(answer)
