friends = int(input())
gift = list(map(int,input().strip().split()))
list = []
for number in range(friends):
    a=gift.index(number+1) + 1
    list.append(a)
print(*list)
            
    