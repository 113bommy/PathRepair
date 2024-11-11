participants, regions = map(int, input().split())
final_result = {}
for i in range(participants):
    name, region, score = input().split()
    if region in final_result:
        final_result[region].append([int(score), name])
    else:
        final_result[region] = [[int(score), name]]
for i in range(1,regions+1):
    j = str(i)
    if len(final_result[j]) > 2:
        final_result[j].sort()
        if final_result[j][-3][0] == final_result[j][-2][0]:
            print('?')
        else:
            print(final_result[j][-1][1], final_result[j][-2][1])
    else:
        print(final_result[j][1][1], final_result[j][0][1])