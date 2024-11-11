def solve(exercises):

    chest = sum(exercises[0::3])
    biceps = sum(exercises[1::3])
    back = sum(exercises[2::3])

    alist=[[chest,"chest"],[biceps,"biceps"],[back,"back"]]
    alist.sort()
    #print(alist)
    return alist[-1][1]


n = int(input())
exercises = list(map(int, input().split(" ")))

print(solve(exercises))