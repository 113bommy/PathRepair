from itertools import combinations
n,m = map(int,filter(None,input().split(' ')))
arr_a = list(map(int,filter(None,input().split(' '))))
# arr_a = sorted(arr_a)
arr_b = []
# for a in range(0,len(arr_a)):
#     # a1 = arr_a[a-1]
#     # a2 = arr_a[a]
#     # diff = abs(a1-a2)
#     arr_b.append(arr_a[a]%m)
if n<=m:
    # main_arr = []
    # for x,y in combinations(range(len(arr_b)+1),r=2):
    #     main_arr.append(arr_b[x:y])

    mul = 1
    # for m_a in main_arr:
    #     sum_ = 0
    #     for j in m_a:
    #         sum_+=int(j)
    #     mul*=sum_%m
    #     mul = mul%m
    for i in range(0,len(arr_a)):
        for j in range(i+1,len(arr_a)):
            mul = mul*(abs(arr_a[i]-arr_a[j]))%m
            mul = mul%m
# else:
#     mul = 0
else:
    mul = 0
print(mul)

