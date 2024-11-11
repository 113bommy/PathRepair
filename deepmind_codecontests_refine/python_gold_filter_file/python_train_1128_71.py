li = [0]*9

n = int(input())
a = list(map(int,input().split()))

for i in a:
    if i//400 > 7:
        li[8] += 1
    else:
        li[i//400] = 1

print(max(1,sum(li[:-1])),sum(li))