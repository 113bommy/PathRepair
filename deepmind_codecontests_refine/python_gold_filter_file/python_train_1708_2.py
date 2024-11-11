def solve(ans,flag,sum_a,sum_b):
    #print(ans,flag,sum_a,sum_b)
    if len(ans) == m+1:
        return ans

    #print(ww)

    for w in ww:
        if flag == 0:
            if sum_a+w > sum_b and ans[-1] != w:
                ans.append(w)
                sum_a += w
                dd = solve(ans,1,sum_a,sum_b)
                if dd != []:
                    return ans

                sum_a -= w
                ans.pop()

        elif flag == 1:
            if sum_b+w > sum_a and ans[-1] != w:
                ans.append(w)
                sum_b += w
                dd = solve(ans,0,sum_a,sum_b)
                if dd != []:
                    return ans

                sum_b -= w
                ans.pop()

    return []

s = input()
m = int(input())

ww = []
for i in range(len(s)):
    if s[i] == '1':
        ww.append(i+1)

res = solve([0],0,0,0)
res = res[1:]
if len(res) == 0:
    print('NO')
else:
    print('YES')
    for num in res:
        print(num,end= " ")
