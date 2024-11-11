n,h = map(int,input().split())
array = list(map(int,input().split()))
total = 0
for number in array:
    total += 1 if number <= h else 2

print(total)
