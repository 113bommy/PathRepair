n = int(input())
teamsize = 0
boxers = list(map(int, input().split()))
countin = [0]*150002
countout = [0]*150002
for boxer in boxers:
    countin[boxer] += 1
# print(countin[:10])
for i in range(1,150001):
    # print("-------------------")
    if countin[i] and countout[i-1]==0 and i>1:
        # print("Gotcha -")
        teamsize += 1
        countin[i] -= 1
        countout[i-1] = 1
    if countin[i] and countout[i] == 0:
        # print("Gotcha 0")
        teamsize += 1
        countin[i] -= 1
        countout[i] += 1
    if countin[i] and countout[i+1]==0:
        # print("Gotcha +")
        teamsize += 1
        countin[i] -= 1
        countout[i+1] += 1
print(teamsize)