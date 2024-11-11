n_snow_drifts = int(input())

snow_drifts = []
groups = 0

def signalize(u):
    if snow_drifts[u][2] == 0:
        snow_drifts[u][2] = 1
        for i in range(n_snow_drifts):
            if snow_drifts[i][0] == snow_drifts[u][0] or snow_drifts[i][1] == snow_drifts[u][1]:
                signalize(i)
    

for i in range(n_snow_drifts):
    aux_input1, aux_input2 = input().split(" ")
    snow_drifts.append([aux_input1, aux_input2, 0])


for i in range(n_snow_drifts):
    if snow_drifts[i][2] == 0:
        groups+=1
        signalize(i)

print(groups-1)