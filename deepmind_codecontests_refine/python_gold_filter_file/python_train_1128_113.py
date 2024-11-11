
N = int(input())

a = list(map(int,input().split()))


dic = {}
free = 0

for i in a:

    if i // 400 < 8:

        dic[i//400] = 1

    else:

        free += 1

print( max(1,len(dic)) ,  len(dic) + free )