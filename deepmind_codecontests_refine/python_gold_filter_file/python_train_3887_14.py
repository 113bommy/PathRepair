N = int(input())
number = input()
l = [int(x) for x in number.split()]
l.sort(reverse=True)
total = 0
coin = 0
j = 0
for i in range(0, N) :
    total = total + l[i]

for i in range(0,N) :
    if coin > total/2 :
        break
    else :
        coin = coin + l[i]
        j += 1

print(j)
