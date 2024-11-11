n = int(input());l = [0]*9
for i in map(int, input().split()):l[min(8,i//400)]+=1
mn = len(list(filter(lambda x:x>0, l[:8])))
print(max(1, mn), mn+l[8])