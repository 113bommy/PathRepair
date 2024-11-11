m = float('+inf')
dict = {'A':m,'B':m,'C':m,'AB':m,'BC':m,'AC':m,'ABC':m}
n = int(input())
for i in range(n):
    k = input().split()
    k[0] = int(k[0])

    if 'A' in k[1]:
        dict['A']=min(dict['A'],k[0])
    if 'B' in k[1]:
        dict['B']=min(dict['B'],k[0])
    if 'C' in k[1]:
        dict['C']=min(dict['C'],k[0])
    if 'A' in k[1] and'B' in k[1]:
        dict['AB']=min(dict['AB'],k[0])
    if 'A' in k[1] and 'C' in k[1]:
        dict['AC'] = min(dict['AC'], k[0])
    if 'C' in k[1] and 'B' in k[1]:
        dict['BC'] = min(dict['BC'], k[0])
    if 'A' in k[1] and 'B' in k[1] and 'C' in k[1]:
        dict['ABC'] = min(dict['ABC'], k[0])

a = min(dict['ABC'],dict['A']+dict['B']+dict['C'],dict['AB']+dict['C'],dict['BC']+dict['A'],dict['B']+dict['AC'])

print(-1 if a==m else a)