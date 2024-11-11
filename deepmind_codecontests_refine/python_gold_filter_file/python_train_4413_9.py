
n = int(input())

arr = [int(i) for i in input().split()]

s,t = map(int, input().split())
if s == t :
    print(0)
    exit()
ans = 0
for i in range (min(s , t) - 1 , max(s , t) - 1) :
    ans = ans + arr[i]

index = 0

for i in range (max(s , t) - 1 , n) :
    index += arr[i]

if min(s , t) != 1 :
    for i in range (0 , min(s , t) - 1) :
        index += arr[i]

ans = min(ans , index)


print(ans)



