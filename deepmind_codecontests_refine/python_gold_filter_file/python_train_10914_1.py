# D
N = int(input())
s = list(map(int, list(input())))

        
def calc_add(temp_list):
    if len(temp_list) <= 1:
        return 0
    else:
        res = 0
        # use 101 for left
        dp_l = [0]*len(temp_list)
        # use 101 for right 
        dp_r = [0]*len(temp_list)
        # do not use 101
        dp_c = [0]*len(temp_list)
        for i in range(len(temp_list) - 1):
            if temp_list[i] > 1:
                dp_l[i+1] = max(dp_l[i] + temp_list[i] - 1, dp_c[i] + temp_list[i])
            else:
                dp_l[i+1] = dp_c[i] + temp_list[i]
            if temp_list[i] > 1:
                dp_r[i+1] = max(dp_l[i] + temp_list[i+1], dp_c[i] + temp_list[i+1], dp_r[i] + temp_list[i+1] - 1)
            else:
                dp_r[i+1] = dp_c[i] + temp_list[i+1]
            dp_c[i+1] = max(dp_l[i], dp_r[i], dp_c[i])
        
        return max(dp_l[-1], dp_r[-1], dp_c[-1])
    

cont0 = 1
cont00 = 1
temp_list = []
res = 0

for i in range(N):
    if s[i] == 1:
        if cont0 == 1:
            temp_list.append(1)
            cont0 = 0
            cont00 = 0
        else:
            temp_list[-1] += 1
    else:
        if cont00 == 1:
            pass
        elif cont0 == 1:
            cont00 = 1
            res += calc_add(temp_list)
            temp_list = []
        else:
            cont0 = 1
            
    if i == N - 1:
        res += calc_add(temp_list)
        
print(res)