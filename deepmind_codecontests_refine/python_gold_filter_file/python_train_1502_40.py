
s = list(input())
nb , ns , nc = map(int,input().split())
pb , ps , pc = map(int ,input().split())
m = int(input())

l , r = 0 , 10**14+1
while l < r :
    mid = (l + r) // 2
    #print('mid = ' , mid )
    cost1 = max(0 , (mid * s.count('B') - nb) * pb)
    cost2 = max(0 , (mid * s.count('S') - ns) * ps)
    cost3 = max(0 , (mid * s.count('C') - nc) * pc)

    if (cost1+cost2+cost3 <= m):
        l = mid + 1
    else:
        r = mid
    #print('l = ' , l , 'r = ' , r)


print(r - 1)


