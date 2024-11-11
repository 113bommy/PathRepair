from bisect import bisect_left

D = int(input())
C = [0]+list(map(int, input().split()))

S = [0]+[[0] + list(map(int, input().split())) for _ in range(D)]

contest = [[0] for _ in range(27)]

#SL:満足度、sch：スケジュール
SL, sch = 0, [0]

#tの日程でコンテストを行った時の満足度を計算
for d in range(1, D+1):
    t = int(input())
    sch.append(t)
    #コンテストの開催日時を記録
    contest[t].append(d)
    SL += S[d][t]

    for i in range(1, 27):
        SL -= C[i]*(d-contest[i][-1])

for i in range(1, 27):
    contest[i].append(D+1)

# print("contest", contest)
# print("sch", sch)
# print(S)
M = int(input())
for i in range(M):
    d, q = map(int, input().split())
    SL += S[d][q]-S[d][sch[d]]

    # print("1", contest[sch[d]])
    ind = bisect_left(contest[sch[d]], d)
    # print("2", ind)
    k = d-contest[sch[d]][ind-1]
    l = contest[sch[d]][ind+1]-d
    SL -= C[sch[d]]*k*l
    del contest[sch[d]][ind]

    ind = bisect_left(contest[q], d)
    contest[q].insert(ind, d)
    k = d-contest[q][ind-1]
    l = contest[q][ind+1]-d
    SL += C[q]*k*l
    sch[d] = q
    print(SL)